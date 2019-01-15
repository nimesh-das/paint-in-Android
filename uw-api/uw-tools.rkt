#lang racket

(require "uw-api.rkt")

; CS136 W14: Assignment 1.5
; NIMESH DAS 20467773

; this module has user-friendly functions that 
; helps you to interact with the uw-api in order to 
; obtain information about the university

(provide 
 course-desc 
 online? 
 course-sections 
 course-capacity 
 section-info
 next-holiday
 room-status)

; course-desc: String Int -> String
; PRE: String is non empty, and is a UW subject
; POST: returns a string with the calendar "description"
;       of the course
; (course-desc subject catalog) takes in a non-empty string, 
; (which is a UW subject) and an Int (catalog) and obtains a 
; course description of the UW subject+catalog

; online?: String Int -> Bool
; PRE: String is non empty, and is a UW subject
; POST: returns #t or #f 
; (online? subject catalog) takes in a non-empty string, 
; (which is a UW subject) and an Int (catalog) and produces
; #t if the respective course is available online and #f
; otherwise

; course-sections: Int String Int -> (listof String)
; PRE: String is non-empty, and is a UW subject
;      term (first Int) is a 4-digit integer that uses UW's 
;      term numbering system
;      Catalog (third Int) is an integer corresponding 
;      the course number
; POST: produces a list of strings that correspond to the 
;       section names for the course
; (course-sections term subject catalog) takes in a 4-digit int,
;  term, a non-empty string, subject (which is a UW subject),
;  and an Int, catalog, and produces a list of strings
;  that correspond to the section names for the course 
;  For example, (course-sections 1141 "CS" 136) => 
;  '("LEC 001" "LEC 002" ... "TST 201")

; course-capacity: Int String Int -> (listof (list String Nat Nat))
; PRE: String is non-empty, and is a UW subject
;      term (first Int) is a 4-digit integer that uses UW's 
;      term numbering system
;      Catalog (third Int) is an integer corresponding 
;      the course number
; POST: produces a list of lists illustrating how "full" a course is. 
;       For each "LEC" section (each sublist), it must produce a 
;       list with 3 items: 
;       the section, the enrollment_capacity and the enrollment_total 
;      (number of students in the class). 
; (course-capacity term subject catalog) takes in a 4-digit int,
;  term, a non-empty string, subject (which is a UW subject),
;  and an Int, catalog, and produces a list of (list String Nat Nat),
;  which is basically a list of lists containing information about
;  how full a course is. Each sublist contains 3 elements: the section,
;  the enrollment_capacity, and the enrollment_total

; section-info: Int String Int String -> String
; PRE: subject (first String) is non-empty, and is a UW subject 
;      (e.g., "CS" or "MATH"). 
;      term (first Int) is a 4-digit integer that uses UW's 
;      term numbering system (e.g. W14 is 1141.)
;      Catalog (third Int) is an integer corresponding 
;      the course number (e.g., the catalog number for 
;      this course is 136). 
;      section (second String) is a 7 character string corresponding
;      to a course section (e.g., "LEC 001" or "TST 201"). 
; POST: produces a single string with information about a 
;       particular section;
;       The format of the string must be:
;       "[SUBJECT] [CATALOG] [SECTION] [start_time]-[end_time] 
;       [weekdays] [building] [room] [instructor]"
; (section-info term subject catalog section) takes in a 4-digit int,
;  term, a non-empty string, subject, an Int, catalog, and a 7-character
;  string, section, and produces a string with information about a 
;  particular section of a UW course+catalog
;  To illustrate,
; (section-info 1141 "CS" 136 "LEC 001") =>
; "CS 136 LEC 001 08:30-09:50 TTh QNC 2502 Ahmed,Reaz"

; next-holiday: String -> String
; PRE: date (first String) is a 10-character string in 
;      YYYY-MM-DD format (e.g., "2014-01-10") 
; POST: produced string should contain the date of the 
;       holiday followed by a space and then the name of 
;       the holiday
; (next-holiday date) takes in a 10-character string in
;  YYYY-MM-DD format, corresponding to a date, and produces
;  the date of the holiday on or after the date provided
;  For example, (next-holiday "2014-01-10") => 
;  "2014-02-16 Family Day"

; room-status: String Nat String String -> String
; PRE: building (first String) is a non-empty string 
;      corresponding to a campus building (e.g., "MC")
;      room (Nat) is an integer corresponding to a room 
;      number (e.g., 4059) 
;      day (second String) is a 1 or 2 character string 
;      that is one of: "M", "T", "W", "Th", "F"
;      time (fourth String) is a 5 character string in 
;      24-hour format (e.g., "13:30")
; POST: produces a string that displays the course in the 
;       room at that day and time, or "FREE" if the room is 
;       not in use 
;       "[SUBJECT] [CATALOG] [DESCRIPTION]"
; (room-status building room day time) takes in a non-empty string,
; (building), a Nat (room), a 1 or 2 character string (day), and
;  a 5 character string in 24-hour format (time), producing a string
;  which shows the course being taught in the room at the particular 
;  provided time, and otherwise produces "FREE"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; gen fns



; The fns below are used often throughout the uw-tools.rkt module 
; and hence they are described first

; par-to-string-building-room: String Nat -> String
; PRE: building (first String) is a non-empty string corresponding to 
;      a campus building (e.g., "MC")
;      room is a natural corresponding to a room number (e.g., 4059) 
; POST: returns a String
; (par-to-string-building-room building room) takes in a string, building,
; and a natural, room, and produces a string that satisfies the parameter
; of the function uw-tools when calling (uw-api "/buildings/building/room/courses")

(define (par-to-string-building-room building room)
  (string-append "/buildings" "/" building "/" (number->string room) "/courses"))

; par-to-string-sub-cat: String Nat -> String
; PRE: subject (first string) is a non-empty string that is a 
;      UW subject (e.g., "CS" or "MATH") 
;      catalog is a natural corresponding to the course number 
;      (e.g., the catalog number for this course is 136).  
; POST: returns a String
; (par-to-string-sub-cat subject catalog) takes in a string, subject,
; and a natural, catalog, and produces a string that satisfies the parameter
; of the function uw-tools when calling (uw-api "/courses/subject/catalog")

(define (par-to-string-sub-cat subject catalog)
  (string-append "/courses/" subject "/" (number->string catalog)))

; par-to-string-term-sub-cat: Nat String Nat -> String
; PRE: term is a 4-digit natural that uses UW's term numbering system
;      subject (first string) is a non-empty string that is a 
;      UW subject (e.g., "CS" or "MATH") 
;      catalog is a natural corresponding to the course number 
;      (e.g., the catalog number for this course is 136).  
; POST: returns a String in the form "/terms/subject/catalog/schedule"
; (par-to-string-term-sub-cat term subject catalog) takes in a
; natural, term, a string, subject, and a natural, catalog, 
; and produces a string that satisfies the parameter of the 
; function uw-tools when calling (uw-api "/terms/subject/catalog/schedule")

(define (par-to-string-term-sub-cat term subject catalog)
  (string-append "/terms/" 
                 (number->string term)
                 "/"
                 subject "/" 
                 (number->string catalog) 
                 "/schedule"))

; lookup-m: String APIResult -> (listof (union Num String))
; PRE: true
; POST: returns empty or '(union Num String)
; (lookup-m k alst) takes in a string key (k) and an APIResult,
; (alst), and determines if k is within the APIResult. If it's not,
; it produces empty, and if it is, it produces a list containing 
; the associated value corresponding to the key (k). If the string 
; key (k), appears multipe times within the APIResult, 
; look-m will provide all the associated values in a list 
; in the order they appear in APIResult

(define (lookup-m k alst)
(cond
[(empty? alst) empty]
[(equal? k (first alst)) (cons (first (rest alst)) empty)]
[(and (list? (first alst))
      (list? (rest alst))) (append (lookup-m k (first alst))
                                   (lookup-m k (rest alst)))]
[(list? (rest alst)) (lookup-m k (rest alst))]
[else empty]))

; lookup-hybrid: APIResult -> (listof (list String Nat Nat))
; PRE: format of the APIResult for 
;      (uw-api "/terms/term/subject/catalog/schedule") must hold
; POST: returns a list of lists, where each sublist contains a section,
;       its' enrollment capacity and enrollment total
; (lookup-hybrid alst) takes in an APIResult, alst, and produces a list
; of lists, where each sublist is a piece of information about a 
; "LEC" section, containing the section name, its' enrollment 
; capacity and its' enrollment total; the APIResult is a function 
; call in the format of (uw-api "/terms/term/subject/catalog/schedule")

 (define (lookup-hybrid alst)
(cond
  [(empty? alst) empty]
  [(string>? (first (lookup-m "section" (first alst))) "LEC 999") empty]
  [else (append (list (list (first (lookup-m "section" (first alst))) 
                            (first (lookup-m "enrollment_capacity" (first alst)))
                            (first (lookup-m "enrollment_total" (first alst)))))
           (lookup-hybrid (rest alst)))]))

; lookup-reverse2: (union Num String) APIResult -> APIResult
; PRE: true
; POST: returns an APIResult 
; (lookup-reverse2 val alst) takes in a value (union Num String), val, 
; and an APIResult, alst, and determines the (list "key" "val") pair, if present,
; within the list; otherwise, producing empty

(define (lookup-reverse2 val alst)
(cond
[(empty? alst) empty]
[(and (= (length alst) 1)
      (string? (first alst))) 
 (cond 
   [(equal? (first alst) val) alst]
   [else empty])]
[(or (and (list? (first alst))
          (list? (rest alst)))
     (and (list? alst)
          (= (length alst) 1)))
 (append (lookup-reverse2 val (first alst))
         (lookup-reverse2 val (rest alst)))]
[(list? (second alst)) (lookup-reverse2 val (second alst))]
[(equal? val (second alst)) alst]
[(or (string? (second alst))
     (number? (second alst))) empty]
[else empty]))

; section-giver: APIResult APIResult -> APIResult
; PRE: the first APIResult will be in the form of
;      '("section" "LEC XXX") where each X represents a natural
;      the second APIResult will be in the form of the function
;      call (uw-api "/terms/term/subject/catalog/schedule")
; POST: returns an APIResult 
; (section-giver k alst) takes in an APIResult, k, and produces the
; remaining contents of that specific section in which k was found,
; (inclusive of k), resulting in an APIResult. 
; For instance, if k was found in (first alst), section-giver 
; will return the contents after where k was found in the (first alst),
; inclusive of k

(define (section-giver k alst)
  (cond
    [(empty? alst) empty]
    [(list? (member k alst)) alst]
    [(and (list? (first alst))
          (list? (rest alst))) (append (section-giver k (first alst))
                                       (section-giver k (rest alst)))]
    [(list? (rest alst)) (section-giver k (rest alst))]
    [else empty]))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; f

;; Fns below are specifically for next-holiday

; strtolstcon: (listof String) -> (listof (listof Char))
; PRE: true
; POST: returns a list of lists, where each sublist is a
;       corresponding string converted into a list of characters
; (strtolstcon los) takes in a list of Strings, los, and 
; produces a list of lists where each sublist is a list of characters
; corresponding to a string in the los

(define (strtolstcon los)
  (cond
    [(empty? los) empty]
    [else (append (list (string->list (first los)))
                  (strtolstcon (rest los)))]))

; strtolstconsin: String -> (listof Char)
; PRE: true
; POST: returns a list of characters
; (strtolstconsin str) takes in a single string, str, and 
; converts the string into a list of characters 

(define (strtolstconsin str)
  (string->list str))

; minusremover-helper: (listof Char) -> (listof Char)
; PRE: true
; POST: returns a list of characters with the minus signs
;       removed (#\-)
; (minusremover-helper los) takes in a list of characters
; and produces a new list of characters with the minus sign 
; character (#\-) removed

(define (minusremover-helper los)
  (cond
    [(empty? los) empty]
    [(equal? (first los) #\-) (minusremover-helper (rest los))]
    [else (cons (first los)
                (minusremover-helper (rest los)))]))

; minusremover: (listof (listof Char)) -> (listof (listof Char))
; PRE: true
; POST: returns a list of lists, where each sublist of characters 
;       has the minus signs (#\-) removed 
; (minusremover lst) takes in a list of lists, where each sublist
; is a list of characters, and produces a new list of lists,
; with each sublist has the minus sign (#\-) removed

(define (minusremover lst)
  (cond
    [(empty? lst) empty]
    [else (append (list (minusremover-helper (first lst)))
                  (minusremover (rest lst)))]))

; lsttostrcon: (listof (listof char)) -> (listof String)
; PRE: true
; POST: returns a list of Strings 
; (lsttostrcon lolc) takes in a list of lists, where each
;  sublist is a list of characters and produces a list of 
;  strings 

(define (lsttostrcon lolc)
  (cond
    [(empty? lolc) empty]
    [else (append (list (list->string (first lolc)))
                  (lsttostrcon (rest lolc)))]))

; lsttostrconsin: (listof char) -> String
; PRE: true
; POST: returns a String
; (lsttostrconsin lst) takes in a list of characters,
;  producing a string 

(define (lsttostrconsin lst)
  (list->string lst))

; converter-p: String -> Nat
; PRE: date (String) is a a 10-character string in YYYY-MM-DD format 
;      (e.g., "2014-01-10") 
; POST: returns a Nat
; (converter-p par) takes in a 10 character string, corresponding to
;  a date, and returns a number that corresponds to the numbers found
;  within the date; so for the above example, we will get 20140110

(define (converter-p par)
  (string->number (lsttostrconsin (minusremover-helper (strtolstconsin par)))))

; lostoloncon: (listof String) -> (list of Nat)
; PRE: each string corresponds to an 8 character natural, 
;      representing a date in YYYYMMDD format
; POST: returns a list of Natural numbers
; (lostoloncon los) takes in a list of 8 character strings, and returns
; the corresponding list of natural numbers 

(define (lostoloncon los)
  (cond
    [(empty? los) empty]
    [else (append (list (string->number (first los)))
                  (lostoloncon (rest los)))]))

; converter-l: (listof String) -> (list of Nat)
; PRE: each string corresponds to a date in YYYY-MM-DD format
; POST: returns a sorted list (ascending order) of Natural numbers
; (converter-l lst) takes in a list of strings (dates), and returns
; a sorted list of numbers, where each number represents a date
; in YYYYMMDD format

(define (converter-l lst)
  (sort (lostoloncon (lsttostrcon (minusremover (strtolstcon lst)))) <))

; compare: Nat (listof Nat) -> Nat
; PRE: num >= 20120102
; POST: returns a natural number
; (compare num lon) takes in a natural number, num, and a list of
; sorted natural numbers, lon, providing either a direct match, 
; or the next natural number that is greater than the provided
; number (num) from the lon

(define (compare num lon)
  (cond
    [(< num 20120102) #f]
    [(= num (first lon)) (first lon)]
    [(< num (first lon)) (first lon)]
    [else (compare num (rest lon))]))

; numbertoform: Nat -> (list String String)
; PRE: num >= 20120102
; POST: returns a list of two Strings, where the first string is
;       "date" and the second is a date in YYYY-MM-DD format
; (numbertoform num) takes in a natural number, num, and produces 
; a list of two strings, in the format '("date" "YYYY-MM-DD"); 
; this format causes the result to become a key, in determining
; the holiday name for the fn (next-holiday date)

(define (numbertoform num)
; ourlist: Nat -> (list of Char)
; PRE: true
; POST: reurns a list of characters that are in YYYYMMDD format
; (ourlist num) takes in a natural num, and converts it into a
; list of characters, that are in YYYYMMDD format; so essentially
; there are 8 characters, which the first 4 being 
; (list #\Y, #\Y, #\Y, #\Y...#\D) 
  (define ourlist (string->list (number->string num)))
  (define firsthyphen 4)
  (define secondhyphen 2)
  (define thirdhyphen 2)
; numbertoformnew: (listof Char) Nat Nat Nat -> (list of Char)
; PRE: (listof Char) consist of numbers in the form YYYYMMDD
; POST: returns a list of characters that are in YYYY-MM-DD format
; (numbertoformnew lst acc1 acc2 acc3) takes in a list of characters, 
; which are essentially numbers, that are in YYYYMMDD format, and
; converters them into a list of characters in YYYY-MM-DD format  
  (define (numbertoformnew lst acc1 acc2 acc3)
  (cond
    [(empty? lst) empty]
    [(and (= acc1 0)
          (= acc2 0)
          (= acc3 0)) empty]
    [(and (= acc1 0)
          (= acc2 0)) (append (list #\-) (numbertoformnew lst acc3 acc2 acc1))]
    [(= acc1 0)  (append (list #\-) (numbertoformnew lst acc2 acc1 acc3))]
    [else (cons (first lst)
                 (numbertoformnew (rest lst) (sub1 acc1) acc2 acc3))]))
  (define ournewlist (numbertoformnew ourlist firsthyphen secondhyphen thirdhyphen))
  (append (list "date") (list (list->string ournewlist))))

 
; See interface above
(define (next-holiday date)
   (define datetonum (converter-p date))
   (define listofdatestonum (converter-l (lookup-m "date" (uw-api "/events/holidays"))))
   (define nextholinum (compare datetonum listofdatestonum))
   (define newparam (numbertoform nextholinum))
   (define holname (lookup-m "name" (lookup-m newparam (uw-api "/events/holidays"))))
   (define finalresulta (first (lookup-m "date" newparam)))
   (define finalresultb (first holname))
   (string-append finalresulta " " finalresultb))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; a

;Fns for course-desc are at the start of this module

; See Interface Above
(define (course-desc subject catalog)
  (first (lookup-m "description" (uw-api (par-to-string-sub-cat subject catalog)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; b

;Fns for online? are at the start of this module

; See Interface Above
(define (online? subject catalog)
  (or (first (lookup-m "online" 
            (uw-api (par-to-string-sub-cat subject catalog))))
      (first (lookup-m "online_only" 
            (uw-api (par-to-string-sub-cat subject catalog))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; c

;Fns for course-sections are at the start of this module

; See Interface above
(define (course-sections term subject catalog)
  (lookup-m "section" (uw-api (par-to-string-term-sub-cat term subject catalog))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; d

;Fns for course-capacity are at the start of this module

; See Interface above
(define (course-capacity term subject catalog)
  (lookup-hybrid (uw-api (par-to-string-term-sub-cat term subject catalog))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; e

;Fns for section-info are at the start of this module

; See Interface Above
(define (section-info term subject catalog section)
  (define key (lookup-reverse2 section (uw-api (par-to-string-term-sub-cat term subject catalog))))
  (define sectionapi 
    (section-giver key (uw-api (par-to-string-term-sub-cat term subject catalog))))
  (define starttime (lookup-m "start_time" sectionapi))
  (define endtime (lookup-m "end_time" sectionapi))
  (define weekdays (lookup-m "weekdays" sectionapi))
  (define building (lookup-m "building" sectionapi))
  (define room (lookup-m "room" sectionapi))
  (define instructors (lookup-m "instructors" sectionapi))
  (string-append subject " " (number->string catalog) " " section " "
  (first starttime) "-"
  (first endtime) " "
  (first weekdays) " "
  (first building) " "
  (first room) " "
  (first (first instructors))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; g

; Fns below are specifically for room-status

; same-day: String String -> Bool
; PRE: day (first string) is a 1 or 2 character string that is one of:
; "M", "T", "W", "Th", "F"
; weekdays (second String) is a combination of days, or a single day
; POST: returns either #t or #f 
; (same-day dayofdesire dayofclass) takes in a day, dayofdesire, and 
; the weekdays the class runs, dayofclass, and determiens whether there
; is an overlap; if there is, it produces #t, and otherwise #f

(define (same-day dayofdesire dayofclass)
  (define dodlist (string->list dayofdesire))
  (define doclist (string->list dayofclass))
  
; countT: (listof Char) Nat -> Nat
; PRE: true
; POST: returns a natural number that corresponds to 
;       the number of letter T's within the lst
; (countT lst acc) takes in a list of characters, lst, and an
; accumulator natural, acc, producing the number of times
; the character #\T appears within the lst
  
  (define (countT lst acc)
    (cond
      [(empty? lst) acc]
      [(equal? (first lst) #\T) (countT (rest lst) (add1 acc))]
      [else (countT (rest lst) acc)]))
  (define numberofTs (countT doclist 0))
  (cond
    [(and (equal? dayofdesire "T")
          (false? (member #\h doclist))) #t]
    [(and (equal? dayofdesire "T")
          (list? (member #\h doclist)))
     (> numberofTs 1)]
    [(equal? dayofdesire "Th")
     (list? (member #\h doclist))]
    [else (list? (member (first dodlist) doclist))]))

; remove-semicolon-helper: (listof Char) -> (listof Char)
; PRE: true
; POST: returns a list of characters with the semi-colons signs
;       removed (#\:)
; (remove-semicolon-helper loc) takes in a list of characters
; and produces a new list of characters with the semi-colon 
; character (#\:) removed

(define (remove-semicolon-helper loc)
  (cond
    [(empty? loc) empty]
    [(equal? (first loc) #\:) (remove-semicolon-helper (rest loc))]
    [else (cons (first loc)
                (remove-semicolon-helper (rest loc)))]))

; remove-semicolon: (listof (listof Char)) -> (listof (listof Char))
; PRE: true
; POST: returns a list of lists, where each sublist of characters 
;       has the semi-colon (#\:) removed 
; (remove-semicolon lst) takes in a list of lists, where each sublist
; is a list of characters; the function produces a new list of lists,
; with each sublist having the semi-colon char (#\:) removed

(define (remove-semicolon lst)
  (cond
    [(empty? lst) empty]
    [else (append (list (remove-semicolon-helper (first lst)))
                  (remove-semicolon (rest lst)))]))

; strtonumcon: (listof String) -> (listof Nat)
; PRE: true
; POST: returns a list of naturals
; (strtonumcon los) takes in a list of Strings, los, and 
; produces a list of naturals where each natural number 
; corresponds to a respective string in the los

(define (strtonumcon los)
  (cond
    [(empty? los) empty]
    [else (append (list (string->number (first los)))
                  (strtonumcon (rest los)))]))

; stonum: String -> Nat
; PRE: true
; POST: returns a natural number within military time
;       without semicolon
; (stonum str) takes in a string, representing military
; time in the format "XX:XX", where X represents a natural
; number between 0-9; the function produces the respective 
; natural number without the semicolons

(define (stonum str)
  (first (strtonumcon (lsttostrcon (remove-semicolon (list (string->list str)))))))

; class-exists: Nat Nat Nat-> Bool
; PRE: true
; POST: returns either #t or #f 
; (class-exists timeofplay starttime endtime) takes in 3
;  naturals, timeofplay, starttime and endtime, and 
; determines whether or not timeofplay falls in 
; between starttime and endtime; if it does, #t,
; and otherwise #f

(define (class-exists timeofplay starttime endtime)
  (define timeofplayinnum (stonum timeofplay))
  (define starttimeinnum (stonum starttime))
  (define endtimeinnum (stonum endtime))
  (cond
    [(and (<= timeofplayinnum endtimeinnum)
          (>= timeofplayinnum starttimeinnum)) #t]
    [else #f]))

; See Interface Above
(define (room-status building room day time)
  (define setofclasses (uw-api (par-to-string-building-room building room)))
  (define (room-status-helper building room day time lst)
    (cond
      [(empty? lst) "FREE"]
      [(and (same-day day (first (lookup-m "weekdays" (first lst))))
            (class-exists time (first (lookup-m "start_time" (first lst)))
                          (first (lookup-m "end_time" (first lst)))))
       (string-append (first (lookup-m "subject" (first lst))) " "
                      (first (lookup-m "catalog_number" (first lst))) " "
                      (first (lookup-m "title" (first lst))))]
      [else (room-status-helper building room day time (rest lst))]))
  (room-status-helper building room day time setofclasses))




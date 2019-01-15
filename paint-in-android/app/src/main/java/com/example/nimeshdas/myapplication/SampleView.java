package com.example.nimeshdas.myapplication;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * Created by nimeshdas on 2016-07-11.
 */
public class SampleView extends View {

    // Constants
    Paint paint = new Paint();
    Line on_the_go_line;
    ArrayList<Line> list_of_lines;
    Rectangle on_the_go_rectangle;
    ArrayList<Rectangle> list_of_rectangles;
    Circle on_the_go_circle;
    ArrayList<Circle> list_of_circles;
    String selected_icon;
    String selected_color;
    Point current_mouse_pressed;
    ArrayList<Shape> list_of_all_existing_non_filled_shapes;
    Shape selected_shape_old;
    Shape selected_shape_new;
    float selected_stroke;
    ArrayList<ArrayList<Shape> > list_of_filled_shapes;
    ArrayList<Shape> on_the_go_filled_pair;
    ArrayList<Line> lines_under_movement;
    ArrayList<Rectangle> rectangles_under_movement;
    ArrayList<ArrayList<Shape> > filled_shapes_under_movement;
    ArrayList<Circle> circles_under_movement;

    void update_selected_icon(String icon) {
        this.selected_icon = icon;
        invalidate();
    }

    void update_selected_color(String color) {
        this.selected_color = color;
        invalidate();
    }

    void updated_selected_stroke(int thickness) {
        this.selected_stroke = thickness;
        invalidate();
    }

    void change_stroke_type(String type) {
        if (type == "fill") {
            paint.setStyle(Paint.Style.FILL);
        }
        else if (type == "stroke") {
            paint.setStyle(Paint.Style.STROKE);
        }
        invalidate();
    }

    void change_paint_color(int color) {
        paint.setColor(color);
    }

    void change_paint_stroke(float stroke_val) {
        paint.setStrokeWidth(stroke_val);
    }

    public class Shape {

        float stroke_value;
        String color;
        String type;
        boolean filled;

        // placeholder class
        boolean contains(Point point) {
            return false;
        }
        String getType() {
            return type;
        }
        float getStroke_value() {
            return stroke_value;
        }
        String getColor() {
            return color;
        }
        boolean getFilled() {
            return filled;
        }
        float getX() { return -1; }
        float getY() { return -1; }
        Point get_start() { Point p = new Point(-1,-1); return p; }
        Point get_end() { Point p = new Point(-1,-1); return p; }
        float getRadius() { return -1; }
        float getLeft() { return -1; }
        float getRight() { return -1; }
        float getTop() { return -1; }
        float getBottom() { return -1; }

        void setStroke_value(float stroke_value) {
            this.stroke_value = stroke_value;
        }
        void setColor(String color) {
            this.color = color;
        }
        void setFilled(boolean val) {
            this.filled = val;
        }
        void setType(String tp) {
            type = tp;
        }

    }

    SampleView(Context context) {
        super(context);
        setFocusable(true);
        // set original color and stroke
        paint.setColor(Color.BLACK);
        paint.setStyle(Paint.Style.STROKE);

        // Initiate all variables
        selected_icon = "Line";
        selected_color = "Black";

        list_of_lines = new ArrayList<Line>();
        list_of_rectangles = new ArrayList<Rectangle>();
        list_of_circles = new ArrayList<Circle>();
        list_of_all_existing_non_filled_shapes = new ArrayList<Shape>();

        list_of_filled_shapes = new ArrayList<ArrayList<Shape> >();
        on_the_go_filled_pair = new ArrayList<Shape>();

        selected_shape_new = new Shape();
        selected_shape_old = new Shape();

        lines_under_movement = new ArrayList<Line>();
        circles_under_movement = new ArrayList<Circle>();
        rectangles_under_movement = new ArrayList<Rectangle>();
        filled_shapes_under_movement = new ArrayList<ArrayList<Shape> >();
    }

    SampleView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setFocusable(true);
        // set original color and stroke
        paint.setColor(Color.BLACK);
        paint.setStyle(Paint.Style.STROKE);

        // Initiate all variables
        selected_icon = "Line";
        selected_color = "Black";

        list_of_lines = new ArrayList<Line>();
        list_of_rectangles = new ArrayList<Rectangle>();
        list_of_circles = new ArrayList<Circle>();
        list_of_all_existing_non_filled_shapes = new ArrayList<Shape>();

        list_of_filled_shapes = new ArrayList<ArrayList<Shape> >();
        on_the_go_filled_pair = new ArrayList<Shape>();

        selected_shape_new = new Shape();
        selected_shape_old = new Shape();

        lines_under_movement = new ArrayList<Line>();
        circles_under_movement = new ArrayList<Circle>();
        rectangles_under_movement = new ArrayList<Rectangle>();

        filled_shapes_under_movement = new ArrayList<ArrayList<Shape> >();
    }

    public class Point {
        float x;
        float y;
        Point(float x, float y) {
            this.x = x;
            this.y = y;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
        void setX(float x) {
            this.x = x;
        }
        void setY(float y) {
            this.y = y;
        }
        void set(float x, float y) {
            this.x = x;
            this.y = y;
        }
    }

    public class Circle extends Shape {
        float startx;
        float starty;
        float radius;
        Circle(float startx, float starty, float radius) {
            this.startx = startx;
            this.starty = starty;
            this.radius = radius;

            this.setColor(selected_color);
            this.setStroke_value(selected_stroke);
            this.filled = false;
            this.setType("Circle");
        }

        @Override
        float getX() {
            return this.startx;
        }
        @Override
        float getY() {
            return this.starty;
        }
        @Override
        float getRadius() {
            return this.radius;
        }
        void setFrame(float startx, float starty, float radius) {
            this.startx = startx;
            this.starty = starty;
            this.radius = radius;
        }
        void extend(float width, float height) {
            float temp_radius_squared = width*width + height*height;
            double radius_double = Math.sqrt((double)temp_radius_squared);
            this.radius = (float)radius_double;
        }
        @Override
        boolean contains(Point p) {
            if((((p.x - this.startx)*(p.x - this.startx)) + ((p.y - this.starty)*(p.y - this.starty))) <= (this.radius)*(this.radius)) {
                return true;
            } else {
                return false;
            }
        }
    }

    public class Rectangle extends Shape {

        float left;
        float top;
        float right;
        float bottom;
        Rectangle(float left, float top, float right, float bottom) {
            this.left = left;
            this.top = top;
            this.right = right;
            this.bottom = bottom;

            this.setColor(selected_color);
            this.setStroke_value(selected_stroke);
            this.filled = false;
            this.setType("Rectangle");
        }
        @Override
        float getLeft() {
            return this.left;
        }
        @Override
        float getTop() {
            return this.top;
        }
        @Override
        float getRight() {
            return this.right;
        }
        @Override
        float getBottom() {
            return this.bottom;
        }

        @Override
        boolean contains(Point p) {
            if ((p.x >= left) && (p.x <= right) && (p.y >= top) && (p.y <= bottom)) {
                return true;
            } else {
                return false;
            }
        }
        void extend(Point p) {
            this.right = p.x;
            this.bottom = p.y;
        }
    }


    public class Line extends Shape {
        Point start;
        Point end;
        Line(Point start, Point end) {
            this.start = start;
            this.end = end;

            this.setColor(selected_color);
            this.setStroke_value(selected_stroke);
            this.filled = false;
            this.setType("Line");
        }
        Line(float x1, float y1, float x2, float y2) {
            start = new Point(x1,y1);
            end = new Point(x2,y2);

            this.setColor(selected_color);
            this.setStroke_value(selected_stroke);
            this.filled = false;
            this.setType("Line");
        }
        void extend_end(Point updated_point) {
            this.end = updated_point;
        }
        @Override
        Point get_start() {
            return start;
        }
        @Override
        Point get_end() {
            return end;
        }
        public double pointToLineDistance(Point A, Point B, Point P) {
            double normalLength = Math.sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
            return Math.abs((P.x-A.x)*(B.y-A.y)-(P.y-A.y)*(B.x-A.x))/normalLength;
        }
        @Override
        boolean contains(Point p) {
            if (pointToLineDistance(start, end, p) < 5) {
                return true;
            } else {
                return false;
            }
        }
    }

    int string_to_color(String s) {
        if (s == "Red") {
            return Color.RED;
        }
        else if (s == "Blue") {
            return Color.BLUE;
        }
        else if (s == "Green") {
            return Color.GREEN;
        }
        else if (s == "Black") {
            return Color.BLACK;
        }
        else {
            return -1;
        }
    }

    @Override
    public void onDraw(Canvas canvas) {
        //canvas.drawLine(0, 0, canvas.getWidth(), canvas.getHeight(), paint);
        //canvas.drawLine(canvas.getWidth(), 0, 0, canvas.getHeight(), paint);
        //System.out.println("onDraw");

        // Draw all filled shapes
        if ((list_of_filled_shapes != null) && (list_of_filled_shapes.size() > 0)) {
            for (ArrayList<Shape> pair : list_of_filled_shapes) {
                if (pair.get(0).getType() == "Rectangle") {
                    Rectangle border_rec = null;
                    Rectangle filled_rec = null;
                    border_rec = (Rectangle)pair.get(0);
                    filled_rec = (Rectangle)pair.get(1);
                    change_paint_color(string_to_color(border_rec.getColor()));
                    change_paint_stroke(border_rec.getStroke_value());
                    if (border_rec == selected_shape_new) {
                        change_paint_color(Color.MAGENTA);
                        change_paint_stroke(10);
                    }
                    canvas.drawRect(border_rec.getLeft(), border_rec.getTop(), border_rec.getRight(), border_rec.getBottom(), paint);
                    change_stroke_type("fill");
                    change_paint_color(string_to_color(filled_rec.getColor()));
                    canvas.drawRect(filled_rec.getLeft(), filled_rec.getTop(), filled_rec.getRight(), filled_rec.getBottom(), paint);
                    change_stroke_type("stroke");
                    change_paint_color(Color.BLACK);
                    change_paint_stroke(1);

                }
                else if (pair.get(0).getType() == "Circle") {
                    Circle border_cir = null;
                    Circle filled_cir = null;
                    border_cir = (Circle)pair.get(0);
                    filled_cir = (Circle)pair.get(1);
                    change_paint_color(string_to_color(border_cir.getColor()));
                    change_paint_stroke(border_cir.getStroke_value());
                    if (border_cir == selected_shape_new) {
                        change_paint_color(Color.MAGENTA);
                        change_paint_stroke(10);
                    }
                    canvas.drawCircle(border_cir.getX(), border_cir.getY(), border_cir.getRadius(), paint);
                    change_stroke_type("fill");
                    change_paint_color(string_to_color(filled_cir.getColor()));
                    canvas.drawCircle(filled_cir.getX(), filled_cir.getY(), filled_cir.getRadius(), paint);
                    change_stroke_type("stroke");
                    change_paint_color(Color.BLACK);
                    change_paint_stroke(1);
                }
            }
        }

        // Draw all lines in saved list of lines
        if (list_of_lines != null) {
            for (Line cur_l : list_of_lines) {
                change_paint_color(string_to_color(cur_l.getColor()));
                change_paint_stroke(cur_l.getStroke_value());
                if (cur_l == selected_shape_new) {
                    change_paint_color(Color.MAGENTA);
                    change_paint_stroke(10);
                }
                canvas.drawLine(cur_l.get_start().getX(), cur_l.get_start().getY(),
                        cur_l.get_end().getX(), cur_l.get_end().getY(), paint);
                change_paint_color(Color.BLACK);
                change_paint_stroke(1);
            }
        }
        // Draw all rectangles in saved list of rectangles
        if (list_of_rectangles != null) {
            for (Rectangle cur_rec : list_of_rectangles) {
                change_paint_color(string_to_color(cur_rec.getColor()));
                change_paint_stroke(cur_rec.getStroke_value());
                if (cur_rec == selected_shape_new) {
                    change_paint_color(Color.MAGENTA);
                    change_paint_stroke(10);
                }
                canvas.drawRect(cur_rec.getLeft(), cur_rec.getTop(),
                        cur_rec.getRight(), cur_rec.getBottom(), paint);
                change_paint_color(Color.BLACK);
                change_paint_stroke(1);
            }
        }
        // Draw all circles in saved list of circles
        if (list_of_circles != null) {
            for (Circle cur_cir : list_of_circles) {
                change_paint_color(string_to_color(cur_cir.getColor()));
                change_paint_stroke(cur_cir.getStroke_value());
                if (cur_cir == selected_shape_new) {
                    change_paint_color(Color.MAGENTA);
                    change_paint_stroke(10);
                }
                canvas.drawCircle(cur_cir.getX(), cur_cir.getY(), cur_cir.getRadius(), paint);
                change_paint_color(Color.BLACK);
                change_paint_stroke(1);
            }
        }

        // Draw current line
        if (on_the_go_line != null) {
            change_paint_color(string_to_color(on_the_go_line.getColor()));
            change_paint_stroke(on_the_go_line.getStroke_value());
            canvas.drawLine(on_the_go_line.get_start().getX(), on_the_go_line.get_start().getY(),
                    on_the_go_line.get_end().getX(), on_the_go_line.get_end().getY(), paint);
            change_paint_color(string_to_color("Black"));
            change_paint_stroke(1);
        }
        // Draw current rectangle
        else if (on_the_go_rectangle != null) {
            change_paint_color(string_to_color(on_the_go_rectangle.getColor()));
            change_paint_stroke(on_the_go_rectangle.getStroke_value());
            canvas.drawRect(on_the_go_rectangle.getLeft(), on_the_go_rectangle.getTop(),
                    on_the_go_rectangle.getRight(), on_the_go_rectangle.getBottom(), paint);
            change_paint_color(string_to_color("Black"));
            change_paint_stroke(1);
        }
        // Draw current circle
        else if (on_the_go_circle != null) {
            change_paint_color(string_to_color(on_the_go_circle.getColor()));
            change_paint_stroke(on_the_go_circle.getStroke_value());
            canvas.drawCircle(on_the_go_circle.getX(), on_the_go_circle.getY(),
                    on_the_go_circle.getRadius(), paint);
            change_paint_color(string_to_color("Black"));
            change_paint_stroke(1);
        }
        // Draw current filled shape
        else if ((on_the_go_filled_pair != null) && (on_the_go_filled_pair.size() > 0)) {
            if (on_the_go_filled_pair.get(0).getType() == "Circle") {
                change_paint_color(string_to_color(on_the_go_filled_pair.get(0).getColor()));
                change_paint_stroke(on_the_go_filled_pair.get(0).getStroke_value());
                canvas.drawCircle(on_the_go_filled_pair.get(0).getX(), on_the_go_filled_pair.get(0).getY(),
                        on_the_go_filled_pair.get(0).getRadius(), paint);
                change_paint_color(string_to_color(on_the_go_filled_pair.get(1).getColor()));
                change_stroke_type("fill");
                canvas.drawCircle(on_the_go_filled_pair.get(1).getX(), on_the_go_filled_pair.get(1).getY(),
                        on_the_go_filled_pair.get(1).getRadius(), paint);
                change_paint_color(string_to_color("Black"));
                change_paint_stroke(1);
                change_stroke_type("stroke");
            }
            else if (on_the_go_filled_pair.get(0).getType() == "Rectangle") {
                change_paint_color(string_to_color(on_the_go_filled_pair.get(0).getColor()));
                change_paint_stroke(on_the_go_filled_pair.get(0).getStroke_value());
                canvas.drawRect(on_the_go_filled_pair.get(0).getLeft(), on_the_go_filled_pair.get(0).getTop(),
                        on_the_go_filled_pair.get(0).getRight(), on_the_go_filled_pair.get(0).getBottom(), paint);
                change_paint_color(string_to_color(on_the_go_filled_pair.get(1).getColor()));
                change_stroke_type("fill");
                canvas.drawRect(on_the_go_filled_pair.get(1).getLeft(), on_the_go_filled_pair.get(1).getTop(),
                        on_the_go_filled_pair.get(1).getRight(), on_the_go_filled_pair.get(1).getBottom(), paint);
                change_paint_color(string_to_color("Black"));
                change_paint_stroke(1);
                change_stroke_type("stroke");
            }
        }
        //canvas.drawRect(200,200,210,210,paint);
    }

    void refresh_on_the_goes() {
        on_the_go_circle = null;
        on_the_go_line = null;
        on_the_go_rectangle = null;
        on_the_go_filled_pair = null;
        selected_shape_old = null;
        selected_shape_new = null;
    }

    @Override
    public boolean onTouchEvent(MotionEvent arg0) {
        switch (arg0.getAction()) {
            case MotionEvent.ACTION_DOWN:
                //System.out.println("inside action down");
                current_mouse_pressed = new Point(arg0.getX(), arg0.getY());
                refresh_on_the_goes();
                switch (selected_icon) {
                    case "Line":
                        on_the_go_line = new Line(new Point(arg0.getX(), arg0.getY()),
                                new Point(arg0.getX(), arg0.getY()));
                        invalidate();
                        break; // Out of Line
                    case "Rectangle":
                        on_the_go_rectangle = new Rectangle(arg0.getX(), arg0.getY(), arg0.getX() + 1, arg0.getY() + 1);
                        invalidate();
                        break; // Out of Rectangle
                    case "Circle":
                        on_the_go_circle = new Circle(arg0.getX(), arg0.getY(), 1);
                        invalidate();
                        break;
                    case "Selection":
                        for (Shape s : list_of_all_existing_non_filled_shapes) {
                            if (s.contains(current_mouse_pressed)) {
                                selected_shape_old = s;
                                selected_shape_new = s;
                            }
                        }
                        for (ArrayList<Shape> ss : list_of_filled_shapes) {
                            if (ss.get(0).contains(current_mouse_pressed)) {
                                selected_shape_old = ss.get(0);
                                selected_shape_new = ss.get(0);
                            }
                        }
                        invalidate();
                        break;
                    case "Erase":
                        for (Shape s : list_of_all_existing_non_filled_shapes) {
                            if (s.contains(current_mouse_pressed)) {
                                if (s.getType() == "Circle") {
                                    list_of_circles.remove(s);
                                } else if (s.getType() == "Line") {
                                    list_of_lines.remove(s);
                                } else if (s.getType() == "Rectangle") {
                                    list_of_rectangles.remove(s);
                                }
                                list_of_all_existing_non_filled_shapes.remove(s);
                                break;
                            }
                        }
                        invalidate();
                        break;
                    case "Fill":
                        for (Shape s : list_of_all_existing_non_filled_shapes) {
                            if (s.contains(current_mouse_pressed)) {
                                if (s.getType() == "Line") {
                                    s.setColor(selected_color);
                                } else {
                                    Circle filled_cir_temp = null;
                                    Rectangle filled_rec_temp = null;

                                    if (s.getType() == "Circle") {
                                        list_of_circles.remove(s);
                                        filled_cir_temp = new Circle(s.getX() + 1, s.getY() + 1, s.getRadius());
                                    } else if (s.getType() == "Rectangle") {
                                        list_of_rectangles.remove(s);
                                        filled_rec_temp = new Rectangle(s.getLeft() + 1, s.getTop() + 1, s.getRight() - 1, s.getBottom() - 1);
                                    }
                                    ArrayList<Shape> pair_of_filled = new ArrayList<Shape>();
                                    pair_of_filled.add(s);
                                    if (s.getType() == "Circle") {
                                        pair_of_filled.add(filled_cir_temp);
                                    } else if (s.getType() == "Rectangle") {
                                        pair_of_filled.add(filled_rec_temp);
                                    }

                                    list_of_all_existing_non_filled_shapes.remove(s);
                                    pair_of_filled.get(0).setFilled(true);
                                    list_of_filled_shapes.add(pair_of_filled);
                                    on_the_go_filled_pair = pair_of_filled;
                                }
                                break;
                            }
                        }
                        invalidate();
                        break; // Out of Fill
                }
            case MotionEvent.ACTION_MOVE:
                //System.out.println("inside action move");
                switch (selected_icon) {
                    case "Line":
                        Point line_end_point_updated = new Point(arg0.getX(), arg0.getY());
                        on_the_go_line.extend_end(line_end_point_updated);
                        invalidate();
                        break;
                    case "Rectangle":
                        Point rect_end_points_updated = new Point(arg0.getX(), arg0.getY());
                        on_the_go_rectangle.extend(rect_end_points_updated);
                        invalidate();
                        break;
                    case "Circle":
                        float width = (arg0.getX()-current_mouse_pressed.getX());
                        float height = (arg0.getY()-current_mouse_pressed.getY());
                        on_the_go_circle.extend(width, height);
                        invalidate();
                        break;
                    case "Selection":
                        if (selected_shape_old != null) {
                            switch (selected_shape_old.getType()) {
                                case "Line":
                                    list_of_lines.remove(selected_shape_old);
                                    /*
                                    System.out.println("current mouse x: " + current_mouse_pressed.getX());
                                    System.out.println("current mouse y: " + current_mouse_pressed.getY());
                                    System.out.println("arg0.x: " + arg0.getX());
                                    System.out.println("arg0.y: " + arg0.getY());
                                    System.out.println("x1: " + selected_shape_old.get_start().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y1: " + selected_shape_old.get_start().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    System.out.println("x2: " + selected_shape_old.get_end().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y2: " + selected_shape_old.get_end().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    */
                                    Line newline = new Line((selected_shape_old.get_start().getX() + (arg0.getX() - current_mouse_pressed.getX())),
                                            (selected_shape_old.get_start().getY() + (arg0.getY() - current_mouse_pressed.getY())),
                                            (selected_shape_old.get_end().getX() + (arg0.getX() - current_mouse_pressed.getX())),
                                            (selected_shape_old.get_end().getY() + (arg0.getY() - current_mouse_pressed.getY())));
                                    /*
                                    System.out.println("list_of_lines size before: " + list_of_lines.size());
                                    System.out.println("list_of_lines size after: " + list_of_lines.size());
                                    */
                                    list_of_all_existing_non_filled_shapes.remove(selected_shape_old);
                                    list_of_lines.add(newline);
                                    list_of_all_existing_non_filled_shapes.add(newline);
                                    lines_under_movement.add(newline);
                                    selected_shape_new = newline;
                                    if (lines_under_movement.size() > 1) {
                                        list_of_lines.remove(lines_under_movement.get(0));
                                        list_of_all_existing_non_filled_shapes.remove(lines_under_movement.get(0));
                                        lines_under_movement.remove(0);
                                    }
                                    invalidate();
                                    break;

                                case "Rectangle":
                                    if (!selected_shape_old.getFilled()) {
                                        list_of_rectangles.remove(selected_shape_old);
                                    /*
                                    System.out.println("current mouse x: " + current_mouse_pressed.getX());
                                    System.out.println("current mouse y: " + current_mouse_pressed.getY());
                                    System.out.println("arg0.x: " + arg0.getX());
                                    System.out.println("arg0.y: " + arg0.getY());
                                    System.out.println("x1: " + selected_shape_old.get_start().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y1: " + selected_shape_old.get_start().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    System.out.println("x2: " + selected_shape_old.get_end().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y2: " + selected_shape_old.get_end().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    */
                                        Rectangle newrec = new Rectangle((selected_shape_old.getLeft() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (selected_shape_old.getTop() + (arg0.getY() - current_mouse_pressed.getY())),
                                                (selected_shape_old.getRight() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (selected_shape_old.getBottom() + (arg0.getY() - current_mouse_pressed.getY())));
                                    /*
                                    System.out.println("list_of_lines size before: " + list_of_lines.size());
                                    System.out.println("list_of_lines size after: " + list_of_lines.size());
                                    */
                                        list_of_all_existing_non_filled_shapes.remove(selected_shape_old);
                                        list_of_rectangles.add(newrec);
                                        list_of_all_existing_non_filled_shapes.add(newrec);
                                        rectangles_under_movement.add(newrec);
                                        selected_shape_new = newrec;
                                        if (rectangles_under_movement.size() > 1) {
                                            list_of_rectangles.remove(rectangles_under_movement.get(0));
                                            list_of_all_existing_non_filled_shapes.remove(rectangles_under_movement.get(0));
                                            rectangles_under_movement.remove(0);
                                        }
                                    } else {

                                        ArrayList<Shape> pair_to_be_moved = new ArrayList<Shape>();

                                        for(ArrayList<Shape> ss : list_of_filled_shapes) {
                                            if (ss.get(0) == selected_shape_new) {
                                                System.out.println("Here!!!!!1");
                                                pair_to_be_moved.add(ss.get(0));
                                                pair_to_be_moved.add(ss.get(1));
                                                list_of_filled_shapes.remove(ss);
                                                break;
                                            }
                                        }

                                        System.out.println("pair_to_be_moved size: " + pair_to_be_moved.size());
                                    /*
                                    System.out.println("current mouse x: " + current_mouse_pressed.getX());
                                    System.out.println("current mouse y: " + current_mouse_pressed.getY());
                                    System.out.println("arg0.x: " + arg0.getX());
                                    System.out.println("arg0.y: " + arg0.getY());
                                    System.out.println("x1: " + selected_shape_old.get_start().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y1: " + selected_shape_old.get_start().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    System.out.println("x2: " + selected_shape_old.get_end().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y2: " + selected_shape_old.get_end().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    */
                                        Rectangle newrec = new Rectangle((pair_to_be_moved.get(0).getLeft() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (pair_to_be_moved.get(0).getTop() + (arg0.getY() - current_mouse_pressed.getY())),
                                                (pair_to_be_moved.get(0).getRight() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (pair_to_be_moved.get(0).getBottom() + (arg0.getY() - current_mouse_pressed.getY())));
                                        Rectangle newrecfill = new Rectangle((pair_to_be_moved.get(1).getLeft() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (pair_to_be_moved.get(1).getTop() + (arg0.getY() - current_mouse_pressed.getY())),
                                                (pair_to_be_moved.get(1).getRight() + (arg0.getX() - current_mouse_pressed.getX())),
                                                (pair_to_be_moved.get(1).getBottom() + (arg0.getY() - current_mouse_pressed.getY())));
                                        System.out.println("2: " + pair_to_be_moved.size());
                                        /*
                                    System.out.println("list_of_lines size before: " + list_of_lines.size());
                                    System.out.println("list_of_lines size after: " + list_of_lines.size());
                                    */
                                        ArrayList<Shape> newpair = new ArrayList<Shape>();
                                        newpair.add(newrec);
                                        newpair.add(newrecfill);
                                        System.out.println("3:");
                                        list_of_filled_shapes.add(newpair);
                                        filled_shapes_under_movement.add(newpair);
                                        System.out.println("4: ");
                                        selected_shape_new = newrec;
                                        /*
                                        if (filled_shapes_under_movement.size() > 1) {
                                            list_of_filled_shapes.remove(filled_shapes_under_movement.get(0));
                                        }
                                        */
                                        System.out.println("5:");
                                    }

                                    invalidate();
                                    break;

                                case "Circle":
                                    list_of_circles.remove(selected_shape_old);
                                    /*
                                    System.out.println("current mouse x: " + current_mouse_pressed.getX());
                                    System.out.println("current mouse y: " + current_mouse_pressed.getY());
                                    System.out.println("arg0.x: " + arg0.getX());
                                    System.out.println("arg0.y: " + arg0.getY());
                                    System.out.println("x1: " + selected_shape_old.get_start().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y1: " + selected_shape_old.get_start().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    System.out.println("x2: " + selected_shape_old.get_end().getX() + (arg0.getX() - current_mouse_pressed.getX()));
                                    System.out.println("y2: " + selected_shape_old.get_end().getY() + (arg0.getY() - current_mouse_pressed.getY()));
                                    */
                                    Circle newcir = new Circle((selected_shape_old.getX() + (arg0.getX() - current_mouse_pressed.getX())),
                                            (selected_shape_old.getY() + (arg0.getY() - current_mouse_pressed.getY())),
                                            (selected_shape_old.getRadius()));
                                    /*
                                    System.out.println("list_of_lines size before: " + list_of_lines.size());
                                    System.out.println("list_of_lines size after: " + list_of_lines.size());
                                    */
                                    list_of_all_existing_non_filled_shapes.remove(selected_shape_old);
                                    list_of_circles.add(newcir);
                                    list_of_all_existing_non_filled_shapes.add(newcir);
                                    circles_under_movement.add(newcir);
                                    selected_shape_new = newcir;
                                    if (circles_under_movement.size() > 1) {
                                        list_of_circles.remove(circles_under_movement.get(0));
                                        list_of_all_existing_non_filled_shapes.remove(circles_under_movement.get(0));
                                        circles_under_movement.remove(0);
                                    }
                                    invalidate();
                                    break;

                            }
                        }

                        invalidate();
                        break;
                }
                break; // Out of Action_Move
            case MotionEvent.ACTION_UP:
                if (lines_under_movement != null) { lines_under_movement.clear(); }
                if (circles_under_movement != null) { circles_under_movement.clear(); }
                if (rectangles_under_movement!= null) { rectangles_under_movement.clear(); }
                switch (selected_icon) {
                    case "Line":
                        list_of_lines.add(on_the_go_line);
                        list_of_all_existing_non_filled_shapes.add(on_the_go_line);
                        break; // Out of Line
                    case "Rectangle":
                        list_of_rectangles.add(on_the_go_rectangle);
                        list_of_all_existing_non_filled_shapes.add(on_the_go_rectangle);
                        break; // Out of Rectangle
                    case "Circle":
                        list_of_circles.add(on_the_go_circle);
                        list_of_all_existing_non_filled_shapes.add(on_the_go_circle);
                        invalidate();
                        break;
                }
                break; // Out of Action_Up
        }
        return true;
    }

}

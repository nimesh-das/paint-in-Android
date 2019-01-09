#include <iostream>
#include "subject.h"
using namespace std;

Subject::Subject(): numObservers(0) {
  // cout << "SUBJECT" << endl;
}
Subject::~Subject() {}

bool Subject::attach(Observer *o) {
//  cout << maxObservers << endl;
 // cout << "we here?" << endl;
  if (numObservers < maxObservers) {
  //cout << "inside while" << endl;
    observers[numObservers++] = o;
    return true;
  }
    else {
	 // cout << "we here2" << endl;   
	  return false;
	}
}

void Subject::detach(Observer *o) {
  int i;
  for (i = 0; i < numObservers && observers[i] != o; ++i);

  if (i < numObservers && observers[i] == o) {
    for (int j = i; j < numObservers - 1; ++j) {
      observers[j] = observers[j+1];
    }
  }
  if (numObservers > 0) --numObservers;
}

void Subject::notifyObservers() {
  for (int i = 0; i < numObservers; ++i) {
    observers[i]->notify();
  }
}

/*
Name: Cam Benassi, Timothy Manchester, Anil Rao, Jordan Gyaltsen
Lab 7 Group 9
COMP 2010L 803
*/

#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


template<typename T>
class BSTNode {

public:
    // Constructors, etc.
    BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
    BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
    BSTNode& operator= (BSTNode&); // copy assignment operator
    
    // ***** Your group will define/implement the insert function
    // ***** at about line 89 below...
    void insert(const T& data);
    
    // Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
    BSTNode<T>* getRight() const { return _right; }
    T& getData() const { return _data; }
    void setData(const T& data) { _data = data; }

    // Display functions used by operator<<.
    // ***** Your group will define/implement the pre & post display functions
    // ***** at about lines 114 & 127 below...
    void inOrderDisplay(ostream&) const;
    void preOrderDisplay(ostream&) const;
    void postOrderDisplay(ostream&) const;
    
    // The insertion operator below uses in-order display.
    // ***** Change the implementation of this insertion operator
    // ***** in order to switch to pre- or post-order display
    friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
        { b.inOrderDisplay(out); return out; }

        void listify(list<T>&) const;
    
private:
    T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
    
    // private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
    void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
    cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
    _data = b._data;
    _left = _right = nullptr;
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
    cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
    delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
    cout << "BSTNode copy assignment operator: ";
#endif
    _data = b._data;
    _left = _right = nullptr;
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
    return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
    // comment out the next line when you've completed this function!
    //cout << "BSTNode<T>::insert called with data == " << data << endl;
    
    if (data < _data)
  {
    if (_left != nullptr)
    {
      _left->insert(data);
    }
    else
    {
      addLeft(data);
    }
  }
  else if (data > _data)
  {
    if (_right != nullptr)
    {
      _right->insert(data);
    }
    else
    {
      addRight(data);
    }
  }
}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
    if (_left != nullptr) {
        _left->inOrderDisplay(out);
        out << ", ";
    }
    out << _data;
    if (_right != nullptr) {
        out << ", ";
        _right->inOrderDisplay(out);
    }
}


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
    // comment out the next line when you've completed this function!
    //cout << "BSTNode<T>::preOrderDisplay called\n";
    
    out << _data;
  if (_left != nullptr) {
      out << ", ";
        _left->preOrderDisplay(out);
    }
    if (_right != nullptr) {
        out << ", ";
        _right->preOrderDisplay(out);
    }
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
    // comment out the next line when you've completed this function!
    //cout << "BSTNode<T>::postOrderDisplay called\n";
    
    if (_left != nullptr) {
        _left->postOrderDisplay(out);
        out << ", ";
    }
    if (_right != nullptr) {
        _right->postOrderDisplay(out);
      out << ", ";
    }
  out << _data;
}

template<typename T>
void BSTNode<T> ::listify(list<T>& list) const {
    if (_left != nullptr)
    { //left slot
        _left->listify(list);
        
    }
    list.push_back(_data);
    if (_right != nullptr)
    {  //right slot
        _right->listify(list);
    }
}

int main(void) {
    BSTNode<int> iroot(100);
    iroot.insert(10);
    iroot.insert(20);
    iroot.insert(200);
    iroot.insert(300);
    cout << "iroot == " << iroot << endl;
    
    BSTNode<string> sroot("Sunday");
    sroot.insert("Monday");
    sroot.insert("Tuesday");
    sroot.insert("Wednesday");
    sroot.insert("Thursday");
    sroot.insert("Friday");
    sroot.insert("Saturday");
    cout << "sroot == " << sroot << endl;

    BSTNode<int> iroot4(3000);
    iroot4.insert(1000);
    iroot4.insert(2000);
    iroot4.insert(4000);
    iroot4.insert(5000);



  //irootList
    list<int> irootList;
    iroot.listify(irootList);
    cout << "\nCreating irootList via iroot.listify\n\n";

    cout << "irootList (foward iterator) == ";
    list<int>::iterator fi;
    for(fi = irootList.end(); fi != irootList.begin(); ++fi){
      cout << *fi << " ";
    }
    cout << endl;

    cout << "irootList (reverse iterator) == ";
    list<int>::reverse_iterator ri;
      for (ri = irootList.rbegin(); ri != irootList.rend(); ++ri) {
        cout << *fi << " ";
        }
    cout << endl;

    cout << "irootList (ranged for loop) == ";
    for(auto ranged : irootList)
      cout << ranged << " ";
    cout << endl;
    
  //srootList
  list<string> srootList;
  sroot.listify(srootList);
  cout << "\nCreating srootList via sroot.listify\n\n";

  cout << "srootList (foward iterator) == ";
  list<string>::iterator sfi;
    for (sfi = srootList.begin(); sfi != srootList.end(); ++sfi) {
        cout << *sfi << " ";
    }
    cout << endl;

  cout << "srootList (reverse iterator) == ";
  list<string>::reverse_iterator sri;
    for (sri = srootList.rbegin(); sri != srootList.rend(); ++sri) {
        cout << *sri << " ";
    }
    cout << endl;

  cout << "srootList (ranged for loop) == ";
  for(auto ranged : srootList)
    cout << ranged << " ";
  cout << endl;

  //iroot4List
  list<int> irootList4;
  iroot4.listify(irootList4);
  cout << "\niroot4 == " << iroot4 << endl;

  cout << "\nCreating iroot4List via iroot4.listify\n";

  map<string, list<int>> mi{
        make_pair("iroot4List", irootList4),
        make_pair("irootList", irootList)
    };

  cout << "\nContents of map<string, list<int>> mi (using ranged for loops) :\niroot4List: ";
  for (auto x : mi) {
        cout << x.first << " ";
        for(auto y:x.second)
      cout<<y<<" ";
        cout << endl;
    }
  cout << "\nUsing map index operator:\nmi[\"irootlist\"] == ";
  for (auto i:mi["irootList"])
    cout << i << " ";
  cout << endl;
  cout << "mi[\"iroot4List\"] == ";
  for (auto i:mi["iroot4List"])
    cout << i << " ";
  cout << endl << endl;


#ifdef debug
    BSTNode<int> iroot2(iroot); // use copy constructor
    cout << "\nAfter copy constructor:\n";
    cout << "iroot2 == " << iroot2 << endl;
    
    BSTNode<int> iroot3;
    iroot3 = iroot2; // use copy assignment operator
    cout << "\nAfter copy assignment operator:\n";
    cout << "iroot3 == " << iroot3 << endl << endl;
#endif
    
    return 0;
}


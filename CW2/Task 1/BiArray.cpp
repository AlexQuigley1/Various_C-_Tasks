#include "BiArray.h"
#include <iostream>

// default constructor
BiArray::BiArray() {
	//Initilise array to size 5
	internalArray = new int[INITIALCAP]();
	//amount of objects in array to 0
	size_ = 0;
	//initial capacity = 0
	capacity_ = INITIALCAP;
	//starting index for pushFront/pushBack set
	pushBackIndex = internalArray + (INITIALCAP/2);
	pushFrontIndex = internalArray + (INITIALCAP/2);
}
// value constructor
BiArray::BiArray(int arr[], int size)  {
	//Intialise new capacity
	int newCapacity;
	//calculate larger of Initial or 3*Size (LO_THRESHOLD = 3)
	//set newCapacity to larger number
	if ((LO_THRESHOLD * size) > INITIALCAP){
		newCapacity = (LO_THRESHOLD*size);
	}
	else {
		newCapacity = INITIALCAP;
	}
	//set size_ to size
	size_ = size;
	//sets capacity_ to newCapacity calculated
	capacity_ = newCapacity;
	//Initialise empty array
	internalArray = new int[newCapacity]();
	//starting index for pushFront/pushBack calculated
	pushBackIndex = internalArray + size_ + size_;
	pushFrontIndex = internalArray + size_ - 1;
	//fills newly Initialised array with arr[]
	for(int i = 0; i<size; i++){
		*(pushFrontIndex + i + 1) = arr[i];

	}
}

// destructor
BiArray::~BiArray() {
	//deletes all of InternalArray
	delete[] internalArray;
	//set all pointers to nullptr
	internalArray = nullptr;
	pushFrontIndex = nullptr;
	pushBackIndex = nullptr;
}

// copy constructor
BiArray::BiArray(const BiArray& other) {
	//copy size and capacity from other to new BiArray
	size_ = other.getSize();
	capacity_ = other.getCapacity();
	// allocate memory and do deep copy
	internalArray = new int[capacity_]();
	//fill in internalArray with all ints from other.internalArray
	for (int i=0; i < capacity_; ++i) {
		internalArray[i] = *(other.internalArray+i);
	}
	//calulate difference in other.pushFrontIndex and other.internalArray;
	int offset = other.pushFrontIndex-other.internalArray;
	//set front/back indexs for new copied BiArray
	pushFrontIndex = (internalArray+offset);
	pushBackIndex = (pushFrontIndex+size_);

}

// move constructor
BiArray::BiArray(BiArray&& other) {
	//set capacity_ and size_ to other.capacity_ and other.size_
	capacity_ = other.capacity_;
	size_ = other.size_;
	//sets all pointers of BiArray to "steal" from other
	internalArray = other.internalArray;
	pushFrontIndex = other.pushFrontIndex;
	pushBackIndex = other.pushBackIndex;

	//sets pointers in other to nullptr
	other.internalArray = nullptr;
	other.pushFrontIndex = nullptr;
	other.pushBackIndex = nullptr;

}

// copy assignment
BiArray& BiArray::operator=(const BiArray& other) {
	//checks to make sure you dont delete current BiArray
	if (&other != this) {
		//delete internalArray to remove objects
		delete [] internalArray;
		//sets size_ and capacity_ to others size and capacity
		size_ = other.getSize();
	capacity_ = other.getCapacity();

	// allocate memory and do deep copy
	internalArray = new int[capacity_]();
	//use loop to fill internalArray
	for (int i=0; i < capacity_; ++i) {
		internalArray[i] = *(other.internalArray+i);
	}
	//calulate difference in other.pushFrontIndex and other.internalArray;
	int offset = other.pushFrontIndex-other.internalArray;
	//set front/back indexs for new copied BiArray
	pushFrontIndex = (internalArray+offset);
	pushBackIndex = (pushFrontIndex+size_);
	}
	//return new copied BiArray
	return *this;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
	
	if(this != &other) {
		//rotate all variables with a temp variable, current variable and other variable to not lose any while moving
		int* temp = internalArray;
		internalArray = other.internalArray;
		other.internalArray = temp;

		temp = pushFrontIndex;
		pushFrontIndex = other.pushFrontIndex;
		other.pushFrontIndex = temp;

		temp = pushBackIndex;
		pushBackIndex = other.pushBackIndex;
		other.pushBackIndex = temp;

		int tempSize = size_;
		size_ = other.size_;
		other.size_ = tempSize;

		tempSize = capacity_;
		capacity_ = other.capacity_;
		other.capacity_ = tempSize;

	}
	//return moved BiArray
	return *this;
}

bool BiArray::get(int i, int& v) const {
	//checks boundaries then returns false if outside
	if ((i >= size_) || (i < 0)) return false;
	//sets v to BiArray at i
	v = BiArray::operator[](i);
	//returns true
	return true;
}

bool BiArray::set(int i, int v) {
	//check boundaries
	if ((i >= size_) || (i < 0)) return false;
	//set BiArray at i to v
	BiArray::operator[](i) = v;
	//return true once completed
	return true;
}

int BiArray::operator[](int i) const {
	//find ith index from first element
	return (*(pushFrontIndex + i + 1));
}

int& BiArray::operator[](int i) {
	//find ith index from first element (reference)
	return (*(pushFrontIndex + i + 1));
}

void BiArray::push_back(int v) {
	//check boundaries
	if (pushBackIndex>(internalArray + capacity_ - 1)){
		//if outside, resize
		resize();
	}
	if (size_ == 0) {
		//if size is 0 the pushFront/back are equal so recalculate
		*pushBackIndex = v;
		pushFrontIndex--;
	}
	else {
		//set pushBack to value v
		*pushBackIndex = v;
	}
	//move pushBack one space to the right
	pushBackIndex++;
	//increase size by 1 as 1 item is added
	size_++;
}

bool BiArray::pop_back() {
	//check if size is 0 then return false
	if(size_ == 0){
		return false;
	}
	//move index back one space and set to 0, decrease size by 1
	pushBackIndex--;
	*pushBackIndex = 0;
	size_--;
	//check new capacity isnt below 5*size_
	//if it is then resize
	if(capacity_ > (HI_THRESHOLD * size_)) resize();
	
	return true;
}

void BiArray::push_front(int v) {
	//check boundaries
	if (pushFrontIndex<internalArray){
		//if outside, resize
		resize();
	}
	if (size_ == 0) {
		//if size is 0 the pushFront/back are equal so recalculate
		*pushFrontIndex = v;
		pushBackIndex++;
	}
	else {
		//set pushBack to value v
		*pushFrontIndex = v;
	}
	//move pushBack one space to the right
	pushFrontIndex--;
	//increase size by 1 as 1 item is added
	size_++;
}

bool BiArray::pop_front() {
	//check if size is 0 then return false
	if(size_ == 0){
		return false;
	}
	//move index forward one space and set to 0, decrease size by 1
	pushFrontIndex++;
	*pushFrontIndex = 0;
	size_--;
	//check new capacity isnt below 5*size_
	//if it is then resize
	if(capacity_ > (HI_THRESHOLD * size_)) resize();

	return true;
}

int BiArray::getSize() const {
	//returns size_ of array
	return size_;
}

int BiArray::getCapacity() const {
	//returns capacity_ of array
	return capacity_;
}

string BiArray::print() const {
	//Initialise string to return
	string noSpaces = "[";
	for (int i = 0; i < size_; i++) {
		//find if it is the last item in internalArray
		if (i==(size_ - 1)){
			noSpaces = noSpaces + to_string(BiArray::operator[](i));
		}
		else {
			//fill string with BiArray
			noSpaces = noSpaces + to_string(BiArray::operator[](i)) + " ";
		}
	}
	noSpaces = noSpaces + "]";
	return noSpaces;
}

string BiArray::printAll() const {//almost works, just prints 0s as X
	string wholeArray = "";
	cout<<"[";
	for (int i = 0; i < capacity_; i++) {
		if (*(internalArray + i) == 0){
			cout<<*(internalArray+i)<<" ";
		}
		else {
			cout<<*(internalArray+i)<<" ";
		}
	}
	cout<<"]"<<endl;
	return wholeArray;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
	//check if they differ in size
	if(lhs.getSize() != rhs.getSize()) return false;
	//loop through checking for equality
	for(int i=0; i<lhs.getSize(); i++){
		if (lhs[i] != rhs[i]){
			//if not equal return false
			return false;
		}
	}
	return true;
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
	//check if they differ in size and use larger size array
	int tempSize;
	if (lhs.getSize() >= rhs.getSize()) tempSize = lhs.getSize();
	else tempSize = rhs.getSize();
	//loop through checking for equality
	for(int i=0; i<tempSize; i++){
		if (lhs[i] != rhs[i]){ 
			//if not equal return true
			return true;
		}
	}
	return false;
}

void BiArray::resize(){
	//find if capacity should be 3*size or 5
	int newCapacity;
	if ((LO_THRESHOLD * size_) > INITIALCAP){
		newCapacity = (LO_THRESHOLD*size_);
	}
	else {
		newCapacity = INITIALCAP;
	}
		//create new temp pointer for array
		int* temp = new int [newCapacity]();
			//check if size is smaller than 5 to change where pointers are
			if (size_ == 1) {
				for (int i=0 ; i<size_ ; ++i){
					//fill temp array
					*(temp + i + 2) = BiArray::operator[](i);
				}
				//Set pointers based on temp positions
				pushFrontIndex = temp + (INITIALCAP/2) - 1;
				pushBackIndex = temp + (INITIALCAP/2) + 1;
			}
			else {
				//fill array if larger than 5
				for (int i=0 ; i<size_ ; ++i){
					*(temp + i + size_) = BiArray::operator[](i);
				}
				//Set pointers based on temp positions
				pushFrontIndex = temp + size_ - 1;
				pushBackIndex = temp + size_ + size_;
			}
			//deletes internalArray to free up memory
			delete [] internalArray;
			//moves internalArray to "look at " temps position
			internalArray = temp;
			//set temp pointer equal to 0
			temp = nullptr;
			//sets capacity of resized array to newCap
			capacity_ = newCapacity;

}


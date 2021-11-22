#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Rand: public Base{

	private:
		double value;
	public:
		Rand() : value(rand() % 100) {}
		double evaluate(){ return value; }
		string stringify(){ return "{" + to_string(value) + "}"; }
		virtual int number_of_children(){return 0;}
        virtual Base* get_child(int i){
            return nullptr;
        }
        virtual void accept(Visitor* visitor, int index){
            visitor->visit_rand(this);
        }
};

#endif
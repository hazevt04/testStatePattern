#include <iostream>
#include <list>
#include <numeric>
#include <vector>

class State {
   public:
      virtual ~State() { }
      virtual void handle( int num ) = 0;
};

class ConcreteStateA : public State {
   public:
      ~ConcreteStateA() { }

      void handle( int num ) {
         std::cout << "In State A. Num changed to "<< ( num + 1 ) << std::endl;
      }
};

class ConcreteStateB : public State {
   public:
      ~ConcreteStateB() { }

      void handle( int num ) {
         std::cout << "In State B. Num changed to "<< ( num + 2 ) << std::endl;
      }
};

class ConcreteStateC : public State {
   public:
      ~ConcreteStateC() { }

      void handle( int num ) {
         std::cout << "In State C. Num changed to "<< ( num + 3 ) << std::endl;
      }
};

class Context {
   public:
      Context() : state() { 
         num_states = 3;
      }

      ~Context() {
         delete state;
      }

      void setState(State* newstate) {
         if (state) {
            delete state;
         }
         state = newstate;
      }

      void updateState(int num) {
         State* stateA = new ConcreteStateA;
         State* stateB = new ConcreteStateB;
         State* stateC = new ConcreteStateC;

         int select = num % num_states;
         switch( select ) {
            case 0:
               setState( stateA );
               break;
            case 1:
               setState( stateB );
               break;
            case 2:
               setState( stateC );
               break;
            default:
               std::cerr << "ERROR: Invalid num" << std::endl;
         } // end of switch
         state->handle( num );
      } 

      void request() {
         state->handle( 0 );
      }
   private:
      State* state;
      int num_states;
};

int main() {
   
   Context* context = new Context;

   std::list<int> numbers( 9 );
   std::iota( numbers.begin(), numbers.end(), 0 );

   for( auto number: numbers ) {
      std::cout << "For " << number << std::endl;
      context->updateState( number );
   }

   delete context;
   return 0;

}

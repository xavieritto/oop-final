#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Interface */
class Sounder {
    public:
        virtual void makeSound() = 0; //A sounder can make a sound. 
};

class Animal : public Sounder {
    protected:
        string type;
        string name;
        int x, y, z;
    public:
        Animal() {
            x = 0;
            y = 0;
            z = 0;
        }
        string getName() {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }

        void makeSound() {
            cout<<"Silence"<<endl;
        };

        void getPosition() {
            cout<<name<<" is at coordinate (x,y,z): "<<x<<","<<y<<","<<z<<endl;
        }

        //TODO IMPLEMENT THE getType METHOD
        /* The method returns a string containing the value stored in the variable named type
        */
       //YOUR CODE HERE
        

        //TODO IMPLEMENT THE move METHOD.
        /*  The method accept 3 integer parameters, x_delta, y_delta, and z_delta.
            It adds each parameter to the respective x, y, and z field of this class.
            x_delta is added to x, y_delta is added to y, and z_delta is added to z
            It returns nothing.
        */
       //YOUR CODE HERE
        
};

/* Animal Cat says Meow */
class Cat : public Animal {
    public:
        Cat(string name) {
            type =  "Cat";
            this->setName(name);
        }
        void makeSound() {
            cout<<name<<" says Meow!"<<endl;
        }
};


//TODO Implement the Dog class. Ensure the dog says Woof
/* Animal Dog says Woof */
//YOUR CODE HERE


/* Person Class*/
class Person : public Sounder {
    private:
        string name;
        vector<Animal*> pets;
        int x, y, z;
    public:
        Person(string name) {
            this->name = name;
            pets = {};
            x = 0;
            y = 0;
            z = 0;
        }
        void makeSound() {
            cout<<name<<" makes a funny sound"<<endl;
        }
        string getName() {
            return name;
        }
        void adoptPet(Animal* pet) {
            pets.push_back(pet);
            cout<<name<<" adopted "<<pet->getName()<<endl;

        }
        void showPets() {
            int size = pets.size();

            cout<<endl<<name<<" has "<<size<<" pets. "<<"Their names are: ";
            for(int i = 0; i<size;i++) {
                cout<<pets.at(i)->getName()<<" a "<<pets.at(i)->getType();
                if((i+1) < size)
                    cout<<", ";
            }
            cout<<endl;
        }

        void getPosition() {
            cout<<name<<" is at coordinate (x,y,z): "<<x<<","<<y<<","<<z<<endl;
        }

        void locatePets() {
            int size = pets.size();

            for(int i = 0; i<size;i++) {
                cout<<"Pet ";
                pets.at(i)->getPosition();
            }
            cout<<endl;
        }

        //TODO IMPLEMENT THE walkWithPets METHOD.
        /*  The method accept 3 integer parameters, x_delta, y_delta, and z_delta.
            It adds each parameter to the respective x, y, and z field of this class.
            x_delta is added to x, y_delta is added to y, and z_delta is added to z

            It then loops through all pets and calls the move method on each one passing the x_delta, y_delta, and z_delta parameters.
            It returns nothing.
        */
       //YOUR CODE HERE
           
        
};


/* DO NOT EDIT BELOW */
int main() {
    Person person = Person("Doe");
    vector<Animal> animals = {};

    Cat cat = Cat("Tom"); //make a cat called Tom
    cat.makeSound(); //make Tom meow
    Dog dog = Dog("Spike"); //make a dog called Spike
    dog.makeSound(); //make spike bark

    animals.push_back(cat);
    animals.push_back(dog);

    person.adoptPet(&cat);
    person.adoptPet(&dog);

    cat.move(1,1,0);
    dog.move(2,2,0);

    person.makeSound();
    person.showPets();

    person.walkWithPets(2,2,2);
    person.getPosition();
    person.locatePets();
}
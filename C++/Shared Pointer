#include <iostream>
#include <string>

class Car{};

class Test {
public:
    enum TestType{NoTest, ConstDest, Copy, Assignment, SpecialCase};
    Test(const TestType& t_) : _t(t_)  {}
    
    int constDestTest() const;
    int copyTest() const;
    int assignmentTest() const;
    int specialCaseTest() const;
    
    void run() const;
private:
    TestType _t;
    const std::string _help = "Type ONLY ONE from the following values to STDIN to run tests: Construction, Copy, Assignment, SpecialCase";
};

Test::TestType getTestType()
{
    std::string type;
    std::getline(std::cin, type);
    if ( type == "Construction" ) 
        return Test::TestType::ConstDest;
    if ( type == "Copy" )
        return Test::TestType::Copy;
    if ( type == "Assignment" ) 
        return Test::TestType::Assignment;
    if ( type == "SpecialCase" ) 
        return Test::TestType::SpecialCase;
        
    return Test::TestType::NoTest;
}


template<typename T>
class shared_ptr{  
private:
    T *ptr;
    int * count;
public:
    shared_ptr(T* ptr){
        this->ptr=ptr;
        count=new int(1);
    }
    ~shared_ptr(){
        if(count!=nullptr){
            (*count)--;
            if(*count==0){
                delete ptr;
                delete count;
            }
        }
    }
    shared_ptr(const shared_ptr<T>& other){
        ptr=other.ptr;
        count=other.count;
        (*count)++;
    }
    shared_ptr& operator=(const shared_ptr<T>& other){
        // if(count!=nullptr){
        //     (*count)--;
        //     if(*count==0){
        //         delete ptr;
        //     }
        // }
        if(this==&other){
            return *this;
        }
        ptr=other.ptr;
        count=other.count;
        (*count)++;
        return *this; 
    }

    int getCount()
    {
        if(count!=nullptr){
            return *count;
        }
        return 0;
    }
};

int main() {
    Test test(getTestType());
    shared_ptr<int> ptr(new int);
    
    test.run();
    
    return 0;
}

int Test::constDestTest() const
{
    shared_ptr<int> p1(new int);
    shared_ptr<int> p2(new int);
    shared_ptr<int> p3(new int);
    return p1.getCount() + p2.getCount() + p3.getCount();
}

int Test::copyTest() const
{
    shared_ptr<std::string> p1(new std::string);
    shared_ptr<std::string> p2(new std::string);
    shared_ptr<std::string> p3(new std::string);
    shared_ptr<std::string> p4(p1);
    shared_ptr<std::string> p5(p2);
    {
        shared_ptr<std::string> pTemp(p3); //tests also destructor
    }
    return p1.getCount() + p2.getCount() + p3.getCount() + p4.getCount() + p5.getCount();
}

int Test::assignmentTest() const
{
    shared_ptr<Car> p1(new Car);
    shared_ptr<Car> p2(new Car);
    shared_ptr<Car> p3(new Car);
    shared_ptr<Car> p4(new Car);
    shared_ptr<Car> p5(new Car);
    p4 = p1;
    p5 = p1;
    p3 = p4;
    return p1.getCount() + p2.getCount() + p3.getCount() + p4.getCount() + p5.getCount();
}

int Test::specialCaseTest() const
{
    shared_ptr<Car> p1(new Car);
    shared_ptr<Car> p2(new Car);
    shared_ptr<Car> p3(new Car);
    p1 = p1;
    p2 = p1;
    p2 = p2;
    p3 = p3;
    return p1.getCount() + p2.getCount() + p3.getCount();
}
    
void Test::run() const
{
    switch (_t)
    {
        case TestType::ConstDest:
            std::cout << constDestTest();
            break;
        case TestType::Copy:
            std::cout << copyTest();
            break;
        case TestType::Assignment:
            std::cout << assignmentTest();
            break;
        case TestType::SpecialCase:
            std::cout << specialCaseTest();
            break;
        default:
            std::cout << _help;
            break;
    }
}

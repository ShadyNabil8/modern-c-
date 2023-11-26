#include <iostream>
#include <memory>

#define LOG(MSG) std::cout << MSG << std::endl

class Programmer
{
private:
public:
    int x;
    Programmer();
    ~Programmer();
};

Programmer::Programmer()
{
    x = 1;
    LOG("Programmer Created!");
}

Programmer::~Programmer()
{
    LOG("Programmer Destroyed!");
}

// int *CreateArr()
// {
//     // int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     // int *arr = new int[10];
//     // return arr;
// }

std::shared_ptr<Programmer> generateShared()
{
    auto sptr = std::make_shared<Programmer>();
    // Programmer Created
    return sptr;
}

std::unique_ptr<Programmer> generateUnique()
{
    std::unique_ptr sptr = std::make_unique<Programmer>();
    // Programmer Created
    return sptr;
}

int main(int argc, char const *argv[])
{
    ////////////////////////////////////
    // {
    //     Programmer *p = new Programmer;
    // }
    // int *ptr = CreateArr();
    // LOG(ptr[5]);
    ////////////////////////////////////

    ////////////////////////////////////
    // {
    //     auto a = generateShared();
    //     LOG(a.use_count()); // 1
    //     auto b = a;
    //     LOG(b.use_count()); // 2
    // }
    ////////////////////////////////////

    ////////////////////////////////////
    // auto a = generateUnique();
    // // auto b = a; // Error
    // LOG(a->x);    // 1
    // LOG(a.get()); // 0x556c1caf0eb0
    // auto b = std::move(a);
    // LOG(b->x);    // 1
    // LOG(b.get()); // 0x556c1caf0eb0
    // LOG(a.get()); // 0(null)
    // LOG(a->x);    // Segmentation fault
    ////////////////////////////////////

    ////////////////////////////////////
    // auto shared  = generateShared();
    // LOG(shared.use_count()); // 1
    // std::weak_ptr weak = shared;
    // LOG(shared.use_count()); // still 1
    // // We can not derefrence the weak pointer
    // // It has no derefrence operator.
    // // LOG(weak->x);
    // std::shared_ptr reshared = weak.lock();
    // LOG(reshared->x); // 1
    ////////////////////////////////////

    return 0;
}

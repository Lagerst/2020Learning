#include "timer.h"
#include "iostream"
#if defined (WIN32)
#include "Windows.h"
#endif

void Test(int x) {
  std::cout << "ExecutedXXX: " << x << std::endl;
}

int main() {
    Timer* t = new Timer();
    for (int i = 0; i < 10; ++i)
        t->SetDelayedTask(std::bind(&Test, i), 300 * (i + 3));
    for (int i = 0; i < 10; ++i)
        t->SetDelayedTask(std::bind(&Test, 6), 300 * (6 + 3));
    t->WaitTillEnd();
}
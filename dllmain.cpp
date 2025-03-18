#include <Windows.h>
#include <thread>
#include <string>

#include "Roblox.h"

#pragma region
extern "C" __declspec(dllexport) LRESULT NextHook(int a1, WPARAM a2, LPARAM a3)
{
    return CallNextHookEx(nullptr, a1, a2, a3);
}
#pragma endregion

// Made by DimU for fun
// Discord : dimu0771

void main()
{
    executor::initialize();

    executor::HookJob("WaitingHybridScriptsJob");

    executor::addScript(R"(print("Injected and initialized!"))");
    executor::addScript(R"(printidentity())");

    while (true) {}
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::thread(main).detach();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

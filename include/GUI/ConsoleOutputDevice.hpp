#pragma once

#ifdef UE4SS_CONSOLE_COLORS_ENABLED
#include <mutex>
#endif

#include <DynamicOutput/Common.hpp>
#include <DynamicOutput/OutputDevice.hpp>
#include <DynamicOutput/Macros.hpp>

namespace RC::Output
{
    // Very simple class that outputs to stdout
    class ConsoleDevice : public OutputDevice
    {
    public:
#if ENABLE_OUTPUT_DEVICE_DEBUG_MODE
        ConsoleDevice()
        {
            fmt::print("ConsoleDevice opening...\n");
        }

        ~ConsoleDevice() override
        {
            fmt::print("ConsoleDevice closing...\n");
        }
#else
        ~ConsoleDevice() override = default;
#endif

    public:
        auto has_optional_arg() const -> bool override;
        auto receive(File::StringViewType fmt) const -> void override;
        auto receive_with_optional_arg(File::StringViewType fmt, int32_t optional_arg = 0) const -> void override;
    };
}




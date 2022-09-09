#ifndef RONTGEN_CORE_H
#define RONTGEN_CORE_H

#include <chrono>

namespace rontgen {



enum class CollectMode std::uint64_t {
    None = 0,
    Categories = (1 << 0),
    Event = (1 << 1),
    Tags = (1 << 2),
    IO = (1 << 3),
    ContextSwitch = (1 << 4),
    SystemCalls = (1 << 5),
    Locks = (1 << 6),

    Tracing = ContextSwitch | SystemCalls,
    Default = Categories | Event | Tags | Tracing
};

enum class ThreadType {
    NotSet,
    Main, 
    IO,

};

struct LifeCycle {
    virtual ~LifeCycle() noexcept = default;

    virtual void start() = 0;
    virtual void stop() = 0;
};

class Core{
};

using PointInTime = std::chrono::time_point<std::chrono::system_clock>;

inline auto now() {
    return PointInTime::now();
}

class Event {
public:
    Event(const char* fileName, const char * functionName, std::uint32_t lineNumber, std::uint32_t category = 0, const char * name = nullptr) :
        fileName_{fileName}, 
        functionName_{functionName},
        lineNumber_{lineNumber},
        category_{category},
        name_{name}
    {};

    void fire(PointInTime when);

private:    
    const char * fileName_{};
    const char * functionName_{};
    std::uint32_t lineNumber_{};
    std::uint32_t category_{};
    const char * name_{};
};

class Category {
public:
    static std::uint32_t Register(const char *name, std::uint32_t color);
};

struct StandardCategory {
    static const std::uint32_t Startup;
    static const std::uint32_t Shutdown;
};
}

#define RONTGEN_CATEGORY_EVENT(...)  {                                                  \
    static auto event = rontgen::Event{__FILE__, __FUNC__, __LINE__, ##__VAR_ARGS__};   \
    event.fire(rontgen::now());                                                         \
}

#endif
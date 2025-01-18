#ifndef _PRINT_HXX_
#define _PRINT_HXX_
#include <cstdio>
#include <type_traits>
#include <typeinfo>
class Core
{
public:
    template <typename... Args>
    static void print(const Args &...args);
    template <typename T>
    static void input(T &, const char *msg = "");

private:
    template <typename T>
    static void printArg(const T &arg);

    class CoreException : public std::exception
    {
        const char *_msg{};

    public:
        CoreException(const char *msg) : _msg{msg} {};
        const char *what() const noexcept override
        {
            return _msg;
        };
    };
};

template <typename T>
void Core::input(T &out, const char *msg)
{
    Core::print(msg);
    if constexpr (std::is_convertible_v<T, char *>)
    {
        if (sizeof(out) <= 0)
            throw CoreException("string size can't be <1");
        fgets(out, sizeof(out), stdin);
    }
    else if constexpr (std::is_integral_v<T>)
    {
        fscanf(stdin, "%d", &out);
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        fscanf(stdin, "%f", &out);
    }
    else if constexpr (std::is_constructible_v<T, char>)
    {
        fscanf(stdin, "%c", &out);
    }
    else
    {
        throw CoreException("unknown Type!");
    }
};

template <typename... Args>
void Core::print(const Args &...args)
{
    ((printArg(args), 0), ...);
    printArg("\n");
};

template <typename T>
void Core::printArg(const T &arg)
{

    if constexpr (std::is_integral_v<T>)
    {
        fprintf(stderr, "%d ", arg);
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        fprintf(stderr, "%f ", arg);
    }
    else if constexpr (std::is_convertible_v<T, const char *>)
    {
        fprintf(stderr, "%s", arg);
    }
    else
    {
        throw CoreException("Unsupported type,Provide const char* or int,double operatorloading.");
    };
};

#endif
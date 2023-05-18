#pragma once

#define REGISTER_DYNAMICOBJECT(name)                                         \
std::unique_ptr<DynamicObjectBase> Create_##name()                           \
{                                                                            \
    return std::make_unique<name>();                                         \
}                                                                            \
                                                                             \
struct Register##name                                                        \
{                                                                            \
    Register##name()                                                         \
    {                                                                        \
        DynamicObjectFactory::Instance()->Register(#name, Create_##name);    \
    }                                                                        \
} Register_##name;

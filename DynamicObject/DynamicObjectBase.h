#pragma once

class DynamicObjectBase {
public:
    DynamicObjectBase() = default;

    virtual ~DynamicObjectBase() = default;

    virtual void Initialise() {}

    virtual void Release() {}
};

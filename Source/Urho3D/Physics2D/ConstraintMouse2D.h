//
// Copyright (c) 2008-2022 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "../Physics2D/Constraint2D.h"

namespace Urho3D
{

/// 2D mouse constraint component.
class URHO3D_API ConstraintMouse2D : public Constraint2D
{
    URHO3D_OBJECT(ConstraintMouse2D, Constraint2D);

public:
    /// Construct.
    explicit ConstraintMouse2D(Context* context);
    
    /// Destruct.
    ~ConstraintMouse2D() override;
    
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set target.
    /// @property
    void SetTarget(const Vector2& target);
    
    /// Return target.
    /// @property
    const Vector2& GetTarget() const { return target_; }

    /// Set max force.
    /// @property
    void SetMaxForce(float maxForce);
    
    /// Return max force.
    /// @property
    float GetMaxForce() const { return jointDef_.maxForce; }

    /// Set linear stiffness in N/m.
    /// @property
    void SetStiffness(float stiffness);

    /// Return linear stiffness in N/m.
    /// @property
    float GetStiffness() const { return jointDef_.stiffness; }

    /// Set linear damping in N*s/m.
    /// @property
    void SetDamping(float damping);

    /// Return linear damping in N*s/m.
    /// @property
    float GetDamping() const { return jointDef_.damping; }

    /// Calc and set stiffness and damping. Must be used after set owner and other bodies.
    bool SetLinearStiffness(float frequencyHertz, float dampingRatio);

private:
    /// Return joint def.
    b2JointDef* GetJointDef() override;

    /// Box2D joint def.
    b2MouseJointDef jointDef_;
    
    /// Target.
    Vector2 target_;
};

}

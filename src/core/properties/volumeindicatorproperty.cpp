/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2013-2017 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/
#include <inviwo/core/properties/volumeindicatorproperty.h>

namespace inviwo {

PropertyClassIdentifier(VolumeIndicatorProperty, "org.inviwo.VolumeIndicatorProperty");

VolumeIndicatorProperty::VolumeIndicatorProperty(std::string identifier, std::string displayName,
                                                 InvalidationLevel invalidationLevel,
                                                 PropertySemantics semantics)
    : CompositeProperty(identifier, displayName, invalidationLevel, semantics)
    , enable_("enable", "Enable", false, InvalidationLevel::InvalidResources)
    , mode_("mode", "Mode", InvalidationLevel::InvalidResources)
    , plane1_("plane1", "Plane 1")
    , plane2_("plane2", "Plane 2")
    , plane3_("plane3", "Plane 3") {

    addProperty(enable_);
    addProperty(mode_);
    addProperty(plane1_);
    addProperty(plane2_);
    addProperty(plane3_);

    mode_.addOption("plane", "Plane", 0);
    mode_.addOption("cross", "Cross", 1);
    mode_.onChange(this, &VolumeIndicatorProperty::onModeChange);
    
    setCollapsed(true);
    setAllPropertiesCurrentStateAsDefault();
}

VolumeIndicatorProperty::VolumeIndicatorProperty(const VolumeIndicatorProperty& rhs)
    : CompositeProperty(rhs)
    , enable_(rhs.enable_)
    , mode_(rhs.mode_)
    , plane1_(rhs.plane1_)
    , plane2_(rhs.plane2_)
    , plane3_(rhs.plane3_) {
    mode_.onChange(this, &VolumeIndicatorProperty::onModeChange);
    setAllPropertiesCurrentStateAsDefault();
}

VolumeIndicatorProperty& VolumeIndicatorProperty::operator=(const VolumeIndicatorProperty& that) {
    if (this != &that) {
        CompositeProperty::operator=(that);
        enable_ = that.enable_;
        mode_ = that.mode_;
        plane1_ = that.plane1_;
        plane2_ = that.plane2_;
        plane3_ = that.plane3_;
    }
    return *this;
}

VolumeIndicatorProperty* VolumeIndicatorProperty::clone() const {
    return new VolumeIndicatorProperty(*this);
}

VolumeIndicatorProperty::~VolumeIndicatorProperty() {}

void VolumeIndicatorProperty::onModeChange() {}

void VolumeIndicatorProperty::setPlane1(PlaneProperty plane) {
    plane1_ = plane;
}

void VolumeIndicatorProperty::setPlane2(PlaneProperty plane) {
    plane2_ = plane;
}

void VolumeIndicatorProperty::setPlane3(PlaneProperty plane) {
    plane3_ = plane;
}

const PlaneProperty& VolumeIndicatorProperty::getPlane1() const {
    return plane1_;
}

const PlaneProperty& VolumeIndicatorProperty::getPlane2() const {
    return plane2_;
}

const PlaneProperty& VolumeIndicatorProperty::getPlane3() const {
    return plane3_;
}

void VolumeIndicatorProperty::setEnable(bool enable) {
    enable_ = enable;
}

bool VolumeIndicatorProperty::getEnable() const {
    return enable_;
}

void VolumeIndicatorProperty::setMode(OptionPropertyInt mode) {
    mode_ = mode;
}

const OptionPropertyInt& VolumeIndicatorProperty::getMode() const {
    return mode_;
}

}  // namespace

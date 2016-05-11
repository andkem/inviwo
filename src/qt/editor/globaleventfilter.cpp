/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2016 Inviwo Foundation
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

#include <inviwo/qt/editor/globaleventfilter.h>

#include <warn/push>
#include <warn/ignore/all>
#include <QAction>
#include <QEvent>
#include <QApplication>
#include <QGuiApplication>
#include <warn/pop>

namespace inviwo {

GlobalEventFilter::GlobalEventFilter(InteractionStateManager &manager) : manager_(manager) {}

#include <warn/push>
#include <warn/ignore/switch-enum>

bool GlobalEventFilter::eventFilter(QObject *obj, QEvent *event) {
    switch (event->type()) {
        case QEvent::MouseButtonPress:
            if (pressCount_ == 0) manager_.beginInteraction();
            ++pressCount_;
            break;
        case QEvent::MouseButtonRelease:
            if (pressCount_ > 0) {
                --pressCount_;
                if (pressCount_ == 0) manager_.endInteraction();
            }
            break;

        case QEvent::TouchBegin:
            if (pressCount_ == 0) manager_.beginInteraction();
            ++pressCount_;
            break;
        case QEvent::TouchEnd:
            if (pressCount_ > 0) {
                --pressCount_;
                if (pressCount_ == 0) manager_.endInteraction();
            }
            break;
        default:
            break;
    }
    return QObject::eventFilter(obj, event);
}

#include <warn/pop>

} // namespace

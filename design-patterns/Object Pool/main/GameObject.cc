#include "GameObject.h"

void GameObject::SetVisibility(bool now) {
    this->m_visible = now;
}

bool GameObject::isVisible () const {
    return this->m_visible;
}
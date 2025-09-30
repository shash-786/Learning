#include "application.h"

void Application::New() {
    this->m_pdocument = Create();
}


void Application::Open() {
    this->m_pdocument = Create();
    this->m_pdocument->Read();
}


void Application::Save() {
    this->m_pdocument->Write();
}
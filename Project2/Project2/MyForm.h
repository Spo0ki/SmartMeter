#pragma once
#include "modules.h"
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>  // For converting System::String to std::string

namespace MyForm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ SmartMeter;
    private: System::Windows::Forms::Label^ Label2;
    private: System::Windows::Forms::Button^ LoadBTN;
    private: System::Windows::Forms::Button^ SaveBTN;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->SmartMeter = (gcnew System::Windows::Forms::Label());
               this->Label2 = (gcnew System::Windows::Forms::Label());
               this->LoadBTN = (gcnew System::Windows::Forms::Button());
               this->SaveBTN = (gcnew System::Windows::Forms::Button());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->SuspendLayout();
               // 
               // SmartMeter
               // 
               this->SmartMeter->AutoSize = true;
               this->SmartMeter->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->SmartMeter->Location = System::Drawing::Point(488, 9);
               this->SmartMeter->Name = L"SmartMeter";
               this->SmartMeter->Size = System::Drawing::Size(140, 28);
               this->SmartMeter->TabIndex = 0;
               this->SmartMeter->Text = L"Smart Meter";
               // 
               // Label2
               // 
               this->Label2->AutoSize = true;
               this->Label2->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->Label2->Location = System::Drawing::Point(7, 512);
               this->Label2->Name = L"Label2";
               this->Label2->Size = System::Drawing::Size(185, 28);
               this->Label2->TabIndex = 1;
               this->Label2->Text = L"Choose Load file:";
               // 
               // LoadBTN
               // 
               this->LoadBTN->Location = System::Drawing::Point(23, 543);
               this->LoadBTN->Name = L"LoadBTN";
               this->LoadBTN->Size = System::Drawing::Size(137, 34);
               this->LoadBTN->TabIndex = 2;
               this->LoadBTN->Text = L"Browse";
               this->LoadBTN->UseVisualStyleBackColor = true;
               this->LoadBTN->Click += gcnew System::EventHandler(this, &Form1::LoadBTN_Click);
               // 
               // SaveBTN
               // 
               this->SaveBTN->Location = System::Drawing::Point(906, 543);
               this->SaveBTN->Name = L"SaveBTN";
               this->SaveBTN->Size = System::Drawing::Size(137, 34);
               this->SaveBTN->TabIndex = 3;
               this->SaveBTN->Text = L"Save";
               this->SaveBTN->UseVisualStyleBackColor = true;
               // 
               // openFileDialog1
               // 
               this->openFileDialog1->FileName = L"openFileDialog1";
               // 
               // Form1
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1055, 580);
               this->Controls->Add(this->SaveBTN);
               this->Controls->Add(this->LoadBTN);
               this->Controls->Add(this->Label2);
               this->Controls->Add(this->SmartMeter);
               this->MaximizeBox = false;
               this->MinimizeBox = false;
               this->Name = L"Form1";
               this->Text = L"Lecture 7";
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion
    private: System::Void LoadBTN_Click(System::Object^ sender, System::EventArgs^ e) {
        openFileDialog1->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ filePath = openFileDialog1->FileName;
            MessageBox::Show("File selected: " + filePath);

            try {
                vector<signal> waveform;
                std::string stdFilePath = msclr::interop::marshal_as<std::string>(filePath);
                read_csv(stdFilePath, waveform);

                // Display the first 3 elements
                String^ message = "First 3 elements:\n";
                for (size_t i = 0; i < 3 && i < waveform.size(); ++i) {
                    message += "Time: " + waveform[i].time + ", Voltage: " + waveform[i].voltage + ", Current: " + waveform[i].current + "\n";
                }
                MessageBox::Show(message);

                MessageBox::Show("File loaded successfully!");
            }
            catch (const std::exception& ex) {
                MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
            }
        }
    }
    };
}

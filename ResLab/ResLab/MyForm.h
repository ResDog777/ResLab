#pragma once
#include <Math.h>                 // Стандартные библиотеки для необходимой работы данной программы
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h> //Библиотека для конвертации из System::String^ в std::string

using namespace std;

namespace ResLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	// Объявление глобальных переменных

	// Общие переменные
	int count_avg_1; // Для проверки делимости
	int count_avg_2;
	int count_avg_3;
	vector <double> vector_avg_1; // Средний вектор 1
	vector <double> vector_avg_2; // Средний вектор 2
	vector <double> vector_avg_3; // Средний вектор 3

	// Для первого графика
	vector <double> vector_x_1; // Вектор столбца X график 1
	vector <double> vector_y_1; // Вектор столбца Y график 1
	vector <double> vector_z_1; // Вектор столбца Z график 1
	vector <double> vector_T_1; // Вектор столбца T график 1
	vector <string> vector_time_1; // Вектор столбца T график 1
	double freq1 = 0;       // Прибавка по оси X (для частоты и времени)
	double countfreq_1 = 0; // Частота в Гц
	int countclear_x_1 = 0; // Счётчик для добавления/очистки графика
	int countclear_y_1 = 0;
	int countclear_z_1 = 0;
	int countclear_T_1 = 0;

	// Для второго графика
	vector <double> vector_x_2; // Вектор столбца X график 2
	vector <double> vector_y_2; // Вектор столбца Y график 2
	vector <double> vector_z_2; // Вектор столбца Z график 2
	vector <double> vector_T_2; // Вектор столбца T график 2
	vector <string> vector_time_2; // Вектор столбца T график 2
	double freq2 = 0;       // Прибавка по оси X (для частоты и времени)
	double countfreq_2 = 0; // Частота в Гц
	int countclear_x_2 = 0; // Счётчик для добавления/очистки графика
	int countclear_y_2 = 0;
	int countclear_z_2 = 0;
	int countclear_T_2 = 0;

	// Для третьего графика
	vector <double> vector_x_3; // Вектор столбца X график 3
	vector <double> vector_y_3; // Вектор столбца Y график 3
	vector <double> vector_z_3; // Вектор столбца Z график 3
	vector <double> vector_T_3; // Вектор столбца T график 3
	vector <string> vector_time_3; // Вектор столбца T график 3
	double freq3 = 0;       // Прибавка по оси X (для частоты и времени)
	double countfreq_3 = 0; // Частота в Гц
	int countclear_x_3 = 0; // Счётчик для добавления/очистки графика
	int countclear_y_3 = 0;
	int countclear_z_3 = 0;
	int countclear_T_3 = 0;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	//private: System::Windows::Forms::DataVisualization::Charting::CustomLabel^ CustomLabel; // Подключение заметок 
	//private: System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle^ markStyle;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label_chart_1;
	private: System::Windows::Forms::Label^ label_chart_2;
	private: System::Windows::Forms::Label^ label_chart_3;
	private: System::Windows::Forms::TextBox^ textBox_file_1;
	private: System::Windows::Forms::TextBox^ textBox_file_2;
	private: System::Windows::Forms::TextBox^ textBox_file_3;
	private: System::Windows::Forms::Label^ label_date_3;
	private: System::Windows::Forms::Label^ label_date_2;
	private: System::Windows::Forms::Label^ label_date_1;
	private: System::Windows::Forms::Label^ label_freq_3;
	private: System::Windows::Forms::Label^ label_freq_2;
	private: System::Windows::Forms::Label^ label_freq_1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ but_clear;
	private: System::Windows::Forms::Button^ but_close;
	private: System::Windows::Forms::Button^ but_selectfile_1;
	private: System::Windows::Forms::Button^ but_selectfile_2;
	private: System::Windows::Forms::Button^ but_selectfile_3;
	private: System::Windows::Forms::Button^ but_x_3;
	private: System::Windows::Forms::Button^ but_x_2;
	private: System::Windows::Forms::Button^ but_x_1;
	private: System::Windows::Forms::Button^ but_y_3;
	private: System::Windows::Forms::Button^ but_y_2;
	private: System::Windows::Forms::Button^ but_y_1;
	private: System::Windows::Forms::Button^ but_z_3;
	private: System::Windows::Forms::Button^ but_z_2;
	private: System::Windows::Forms::Button^ but_z_1;
	private: System::Windows::Forms::Button^ but_T_3;
	private: System::Windows::Forms::Button^ but_T_2;
	private: System::Windows::Forms::Button^ but_T_1;
	private: System::Windows::Forms::Button^ but_average_3;
	private: System::Windows::Forms::Button^ but_average_2;
	private: System::Windows::Forms::Button^ but_average_1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ but_scale;
	private: System::Windows::Forms::TextBox^ textBox_scale_x_1;
	private: System::Windows::Forms::TextBox^ textBox_scale_x_2;
	private: System::Windows::Forms::ComboBox^ comboBox_average_1;
	private: System::Windows::Forms::ComboBox^ comboBox_average_2;
	private: System::Windows::Forms::ComboBox^ comboBox_average_3;
	private: System::Windows::Forms::TextBox^ textBox_scale_y_2;
	private: System::Windows::Forms::TextBox^ textBox_scale_y_1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox_interval_1;
	private: System::Windows::Forms::Button^ but_interval_1;
	private: System::Windows::Forms::Button^ but_interval_2;
	private: System::Windows::Forms::TextBox^ textBox_interval_2;
	private: System::Windows::Forms::Button^ but_interval_3;
	private: System::Windows::Forms::TextBox^ textBox_interval_3;
	private: System::Windows::Forms::Button^ but_clear_avg_1;
	private: System::Windows::Forms::Button^ but_clear_avg_2;
	private: System::Windows::Forms::Button^ but_clear_avg_3;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::CustomLabel^ customLabel1 = (gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label_chart_1 = (gcnew System::Windows::Forms::Label());
			this->label_chart_2 = (gcnew System::Windows::Forms::Label());
			this->label_chart_3 = (gcnew System::Windows::Forms::Label());
			this->textBox_file_1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_file_2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_file_3 = (gcnew System::Windows::Forms::TextBox());
			this->label_date_3 = (gcnew System::Windows::Forms::Label());
			this->label_date_2 = (gcnew System::Windows::Forms::Label());
			this->label_date_1 = (gcnew System::Windows::Forms::Label());
			this->label_freq_3 = (gcnew System::Windows::Forms::Label());
			this->label_freq_2 = (gcnew System::Windows::Forms::Label());
			this->label_freq_1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->but_clear = (gcnew System::Windows::Forms::Button());
			this->but_close = (gcnew System::Windows::Forms::Button());
			this->but_selectfile_1 = (gcnew System::Windows::Forms::Button());
			this->but_selectfile_2 = (gcnew System::Windows::Forms::Button());
			this->but_selectfile_3 = (gcnew System::Windows::Forms::Button());
			this->but_x_3 = (gcnew System::Windows::Forms::Button());
			this->but_x_2 = (gcnew System::Windows::Forms::Button());
			this->but_x_1 = (gcnew System::Windows::Forms::Button());
			this->but_y_3 = (gcnew System::Windows::Forms::Button());
			this->but_y_2 = (gcnew System::Windows::Forms::Button());
			this->but_y_1 = (gcnew System::Windows::Forms::Button());
			this->but_z_3 = (gcnew System::Windows::Forms::Button());
			this->but_z_2 = (gcnew System::Windows::Forms::Button());
			this->but_z_1 = (gcnew System::Windows::Forms::Button());
			this->but_T_3 = (gcnew System::Windows::Forms::Button());
			this->but_T_2 = (gcnew System::Windows::Forms::Button());
			this->but_T_1 = (gcnew System::Windows::Forms::Button());
			this->but_average_3 = (gcnew System::Windows::Forms::Button());
			this->but_average_2 = (gcnew System::Windows::Forms::Button());
			this->but_average_1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->but_scale = (gcnew System::Windows::Forms::Button());
			this->textBox_scale_x_1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scale_x_2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_average_1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_average_2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_average_3 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_scale_y_2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scale_y_1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox_interval_1 = (gcnew System::Windows::Forms::TextBox());
			this->but_interval_1 = (gcnew System::Windows::Forms::Button());
			this->but_interval_2 = (gcnew System::Windows::Forms::Button());
			this->textBox_interval_2 = (gcnew System::Windows::Forms::TextBox());
			this->but_interval_3 = (gcnew System::Windows::Forms::Button());
			this->textBox_interval_3 = (gcnew System::Windows::Forms::TextBox());
			this->but_clear_avg_1 = (gcnew System::Windows::Forms::Button());
			this->but_clear_avg_2 = (gcnew System::Windows::Forms::Button());
			this->but_clear_avg_3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			customLabel1->Text = L"Тест";
			chartArea1->AxisX->CustomLabels->Add(customLabel1);
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"График 1 x(t)";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"График 1 y(t)";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"График 1 z(t)";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"График 1 T(t)";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Legend = L"Legend1";
			series5->Name = L"График 2 x(t)";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Legend = L"Legend1";
			series6->Name = L"График 2 y(t)";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Legend = L"Legend1";
			series7->Name = L"График 2 z(t)";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Legend = L"Legend1";
			series8->Name = L"График 2 T(t)";
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series9->Legend = L"Legend1";
			series9->Name = L"График 3 x(t)";
			series10->ChartArea = L"ChartArea1";
			series10->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series10->Legend = L"Legend1";
			series10->Name = L"График 3 y(t)";
			series11->ChartArea = L"ChartArea1";
			series11->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series11->Legend = L"Legend1";
			series11->Name = L"График 3 z(t)";
			series12->ChartArea = L"ChartArea1";
			series12->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series12->Legend = L"Legend1";
			series12->Name = L"График 3 T(t)";
			series13->ChartArea = L"ChartArea1";
			series13->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series13->Legend = L"Legend1";
			series13->Name = L"График 1 (среднее)";
			series14->ChartArea = L"ChartArea1";
			series14->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series14->Legend = L"Legend1";
			series14->Name = L"График 2 (среднее)";
			series15->ChartArea = L"ChartArea1";
			series15->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series15->Legend = L"Legend1";
			series15->Name = L"График 3 (среднее)";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Series->Add(series7);
			this->chart1->Series->Add(series8);
			this->chart1->Series->Add(series9);
			this->chart1->Series->Add(series10);
			this->chart1->Series->Add(series11);
			this->chart1->Series->Add(series12);
			this->chart1->Series->Add(series13);
			this->chart1->Series->Add(series14);
			this->chart1->Series->Add(series15);
			this->chart1->Size = System::Drawing::Size(1880, 707);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 741);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Главное меню";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(360, 741);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Путь к файлу";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(514, 741);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Дата создания файла";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(693, 741);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(158, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Частота измерений, Гц";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(872, 741);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"График x(t)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(966, 741);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 16);
			this->label6->TabIndex = 6;
			this->label6->Text = L"График y(t)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(1057, 741);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(76, 16);
			this->label7->TabIndex = 7;
			this->label7->Text = L"График z(t)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(1146, 741);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 16);
			this->label8->TabIndex = 8;
			this->label8->Text = L"График T(t)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(1470, 741);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(144, 16);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Скользящее среднее";
			// 
			// label_chart_1
			// 
			this->label_chart_1->AutoSize = true;
			this->label_chart_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_chart_1->Location = System::Drawing::Point(126, 798);
			this->label_chart_1->Name = L"label_chart_1";
			this->label_chart_1->Size = System::Drawing::Size(66, 16);
			this->label_chart_1->TabIndex = 10;
			this->label_chart_1->Text = L"График 1";
			// 
			// label_chart_2
			// 
			this->label_chart_2->AutoSize = true;
			this->label_chart_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_chart_2->Location = System::Drawing::Point(126, 850);
			this->label_chart_2->Name = L"label_chart_2";
			this->label_chart_2->Size = System::Drawing::Size(66, 16);
			this->label_chart_2->TabIndex = 11;
			this->label_chart_2->Text = L"График 2";
			// 
			// label_chart_3
			// 
			this->label_chart_3->AutoSize = true;
			this->label_chart_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_chart_3->Location = System::Drawing::Point(126, 904);
			this->label_chart_3->Name = L"label_chart_3";
			this->label_chart_3->Size = System::Drawing::Size(66, 16);
			this->label_chart_3->TabIndex = 12;
			this->label_chart_3->Text = L"График 3";
			// 
			// textBox_file_1
			// 
			this->textBox_file_1->Enabled = false;
			this->textBox_file_1->Location = System::Drawing::Point(313, 796);
			this->textBox_file_1->Name = L"textBox_file_1";
			this->textBox_file_1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox_file_1->Size = System::Drawing::Size(189, 20);
			this->textBox_file_1->TabIndex = 13;
			// 
			// textBox_file_2
			// 
			this->textBox_file_2->Enabled = false;
			this->textBox_file_2->Location = System::Drawing::Point(313, 848);
			this->textBox_file_2->Name = L"textBox_file_2";
			this->textBox_file_2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox_file_2->Size = System::Drawing::Size(189, 20);
			this->textBox_file_2->TabIndex = 14;
			// 
			// textBox_file_3
			// 
			this->textBox_file_3->Enabled = false;
			this->textBox_file_3->Location = System::Drawing::Point(313, 904);
			this->textBox_file_3->Name = L"textBox_file_3";
			this->textBox_file_3->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox_file_3->Size = System::Drawing::Size(189, 20);
			this->textBox_file_3->TabIndex = 15;
			// 
			// label_date_3
			// 
			this->label_date_3->AutoSize = true;
			this->label_date_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_date_3->Location = System::Drawing::Point(571, 904);
			this->label_date_3->Name = L"label_date_3";
			this->label_date_3->Size = System::Drawing::Size(39, 16);
			this->label_date_3->TabIndex = 18;
			this->label_date_3->Text = L"Дата";
			// 
			// label_date_2
			// 
			this->label_date_2->AutoSize = true;
			this->label_date_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_date_2->Location = System::Drawing::Point(571, 850);
			this->label_date_2->Name = L"label_date_2";
			this->label_date_2->Size = System::Drawing::Size(39, 16);
			this->label_date_2->TabIndex = 17;
			this->label_date_2->Text = L"Дата";
			// 
			// label_date_1
			// 
			this->label_date_1->AutoSize = true;
			this->label_date_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_date_1->Location = System::Drawing::Point(571, 798);
			this->label_date_1->Name = L"label_date_1";
			this->label_date_1->Size = System::Drawing::Size(39, 16);
			this->label_date_1->TabIndex = 16;
			this->label_date_1->Text = L"Дата";
			// 
			// label_freq_3
			// 
			this->label_freq_3->AutoSize = true;
			this->label_freq_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_freq_3->Location = System::Drawing::Point(741, 904);
			this->label_freq_3->Name = L"label_freq_3";
			this->label_freq_3->Size = System::Drawing::Size(61, 16);
			this->label_freq_3->TabIndex = 21;
			this->label_freq_3->Text = L"Частота";
			// 
			// label_freq_2
			// 
			this->label_freq_2->AutoSize = true;
			this->label_freq_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_freq_2->Location = System::Drawing::Point(741, 850);
			this->label_freq_2->Name = L"label_freq_2";
			this->label_freq_2->Size = System::Drawing::Size(61, 16);
			this->label_freq_2->TabIndex = 20;
			this->label_freq_2->Text = L"Частота";
			// 
			// label_freq_1
			// 
			this->label_freq_1->AutoSize = true;
			this->label_freq_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_freq_1->Location = System::Drawing::Point(741, 798);
			this->label_freq_1->Name = L"label_freq_1";
			this->label_freq_1->Size = System::Drawing::Size(61, 16);
			this->label_freq_1->TabIndex = 19;
			this->label_freq_1->Text = L"Частота";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(1275, 741);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(72, 16);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Интервал";
			// 
			// but_clear
			// 
			this->but_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_clear->Location = System::Drawing::Point(15, 791);
			this->but_clear->Name = L"but_clear";
			this->but_clear->Size = System::Drawing::Size(90, 30);
			this->but_clear->TabIndex = 28;
			this->but_clear->Text = L"Очистить";
			this->but_clear->UseVisualStyleBackColor = true;
			this->but_clear->Click += gcnew System::EventHandler(this, &MyForm::but_clear_Click);
			// 
			// but_close
			// 
			this->but_close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_close->Location = System::Drawing::Point(15, 844);
			this->but_close->Name = L"but_close";
			this->but_close->Size = System::Drawing::Size(90, 30);
			this->but_close->TabIndex = 29;
			this->but_close->Text = L"Закрыть";
			this->but_close->UseVisualStyleBackColor = true;
			this->but_close->Click += gcnew System::EventHandler(this, &MyForm::but_close_Click);
			// 
			// but_selectfile_1
			// 
			this->but_selectfile_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->but_selectfile_1->Location = System::Drawing::Point(204, 791);
			this->but_selectfile_1->Name = L"but_selectfile_1";
			this->but_selectfile_1->Size = System::Drawing::Size(90, 30);
			this->but_selectfile_1->TabIndex = 30;
			this->but_selectfile_1->Text = L"Добавить";
			this->but_selectfile_1->UseVisualStyleBackColor = true;
			this->but_selectfile_1->Click += gcnew System::EventHandler(this, &MyForm::but_selectfile_1_Click);
			// 
			// but_selectfile_2
			// 
			this->but_selectfile_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->but_selectfile_2->Location = System::Drawing::Point(204, 843);
			this->but_selectfile_2->Name = L"but_selectfile_2";
			this->but_selectfile_2->Size = System::Drawing::Size(90, 30);
			this->but_selectfile_2->TabIndex = 31;
			this->but_selectfile_2->Text = L"Добавить";
			this->but_selectfile_2->UseVisualStyleBackColor = true;
			this->but_selectfile_2->Click += gcnew System::EventHandler(this, &MyForm::but_selectfile_2_Click);
			// 
			// but_selectfile_3
			// 
			this->but_selectfile_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->but_selectfile_3->Location = System::Drawing::Point(204, 897);
			this->but_selectfile_3->Name = L"but_selectfile_3";
			this->but_selectfile_3->Size = System::Drawing::Size(90, 30);
			this->but_selectfile_3->TabIndex = 32;
			this->but_selectfile_3->Text = L"Добавить";
			this->but_selectfile_3->UseVisualStyleBackColor = true;
			this->but_selectfile_3->Click += gcnew System::EventHandler(this, &MyForm::but_selectfile_3_Click);
			// 
			// but_x_3
			// 
			this->but_x_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_x_3->Location = System::Drawing::Point(875, 903);
			this->but_x_3->Name = L"but_x_3";
			this->but_x_3->Size = System::Drawing::Size(70, 30);
			this->but_x_3->TabIndex = 35;
			this->but_x_3->Text = L"x(t)";
			this->but_x_3->UseVisualStyleBackColor = true;
			this->but_x_3->Click += gcnew System::EventHandler(this, &MyForm::but_x_3_Click);
			// 
			// but_x_2
			// 
			this->but_x_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_x_2->Location = System::Drawing::Point(875, 849);
			this->but_x_2->Name = L"but_x_2";
			this->but_x_2->Size = System::Drawing::Size(70, 30);
			this->but_x_2->TabIndex = 34;
			this->but_x_2->Text = L"x(t)";
			this->but_x_2->UseVisualStyleBackColor = true;
			this->but_x_2->Click += gcnew System::EventHandler(this, &MyForm::but_x_2_Click);
			// 
			// but_x_1
			// 
			this->but_x_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_x_1->Location = System::Drawing::Point(875, 797);
			this->but_x_1->Name = L"but_x_1";
			this->but_x_1->Size = System::Drawing::Size(70, 30);
			this->but_x_1->TabIndex = 33;
			this->but_x_1->Text = L"x(t)";
			this->but_x_1->UseVisualStyleBackColor = true;
			this->but_x_1->Click += gcnew System::EventHandler(this, &MyForm::but_x_1_Click);
			// 
			// but_y_3
			// 
			this->but_y_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_y_3->Location = System::Drawing::Point(969, 903);
			this->but_y_3->Name = L"but_y_3";
			this->but_y_3->Size = System::Drawing::Size(70, 30);
			this->but_y_3->TabIndex = 38;
			this->but_y_3->Text = L"y(t)";
			this->but_y_3->UseVisualStyleBackColor = true;
			this->but_y_3->Click += gcnew System::EventHandler(this, &MyForm::but_y_3_Click);
			// 
			// but_y_2
			// 
			this->but_y_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_y_2->Location = System::Drawing::Point(969, 849);
			this->but_y_2->Name = L"but_y_2";
			this->but_y_2->Size = System::Drawing::Size(70, 30);
			this->but_y_2->TabIndex = 37;
			this->but_y_2->Text = L"y(t)";
			this->but_y_2->UseVisualStyleBackColor = true;
			this->but_y_2->Click += gcnew System::EventHandler(this, &MyForm::but_y_2_Click);
			// 
			// but_y_1
			// 
			this->but_y_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_y_1->Location = System::Drawing::Point(969, 797);
			this->but_y_1->Name = L"but_y_1";
			this->but_y_1->Size = System::Drawing::Size(70, 30);
			this->but_y_1->TabIndex = 36;
			this->but_y_1->Text = L"y(t)";
			this->but_y_1->UseVisualStyleBackColor = true;
			this->but_y_1->Click += gcnew System::EventHandler(this, &MyForm::but_y_1_Click);
			// 
			// but_z_3
			// 
			this->but_z_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_z_3->Location = System::Drawing::Point(1061, 903);
			this->but_z_3->Name = L"but_z_3";
			this->but_z_3->Size = System::Drawing::Size(70, 30);
			this->but_z_3->TabIndex = 41;
			this->but_z_3->Text = L"z(t)";
			this->but_z_3->UseVisualStyleBackColor = true;
			this->but_z_3->Click += gcnew System::EventHandler(this, &MyForm::but_z_3_Click);
			// 
			// but_z_2
			// 
			this->but_z_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_z_2->Location = System::Drawing::Point(1061, 849);
			this->but_z_2->Name = L"but_z_2";
			this->but_z_2->Size = System::Drawing::Size(70, 30);
			this->but_z_2->TabIndex = 40;
			this->but_z_2->Text = L"z(t)";
			this->but_z_2->UseVisualStyleBackColor = true;
			this->but_z_2->Click += gcnew System::EventHandler(this, &MyForm::but_z_2_Click);
			// 
			// but_z_1
			// 
			this->but_z_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_z_1->Location = System::Drawing::Point(1061, 797);
			this->but_z_1->Name = L"but_z_1";
			this->but_z_1->Size = System::Drawing::Size(70, 30);
			this->but_z_1->TabIndex = 39;
			this->but_z_1->Text = L"z(t)";
			this->but_z_1->UseVisualStyleBackColor = true;
			this->but_z_1->Click += gcnew System::EventHandler(this, &MyForm::but_z_1_Click);
			// 
			// but_T_3
			// 
			this->but_T_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_T_3->Location = System::Drawing::Point(1150, 903);
			this->but_T_3->Name = L"but_T_3";
			this->but_T_3->Size = System::Drawing::Size(70, 30);
			this->but_T_3->TabIndex = 44;
			this->but_T_3->Text = L"T(t)";
			this->but_T_3->UseVisualStyleBackColor = true;
			this->but_T_3->Click += gcnew System::EventHandler(this, &MyForm::but_T_3_Click);
			// 
			// but_T_2
			// 
			this->but_T_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_T_2->Location = System::Drawing::Point(1150, 849);
			this->but_T_2->Name = L"but_T_2";
			this->but_T_2->Size = System::Drawing::Size(70, 30);
			this->but_T_2->TabIndex = 43;
			this->but_T_2->Text = L"T(t)";
			this->but_T_2->UseVisualStyleBackColor = true;
			this->but_T_2->Click += gcnew System::EventHandler(this, &MyForm::but_T_2_Click);
			// 
			// but_T_1
			// 
			this->but_T_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_T_1->Location = System::Drawing::Point(1150, 797);
			this->but_T_1->Name = L"but_T_1";
			this->but_T_1->Size = System::Drawing::Size(70, 30);
			this->but_T_1->TabIndex = 42;
			this->but_T_1->Text = L"T(t)";
			this->but_T_1->UseVisualStyleBackColor = true;
			this->but_T_1->Click += gcnew System::EventHandler(this, &MyForm::but_T_1_Click);
			// 
			// but_average_3
			// 
			this->but_average_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_average_3->Location = System::Drawing::Point(1545, 903);
			this->but_average_3->Name = L"but_average_3";
			this->but_average_3->Size = System::Drawing::Size(90, 30);
			this->but_average_3->TabIndex = 47;
			this->but_average_3->Text = L"Построить";
			this->but_average_3->UseVisualStyleBackColor = true;
			this->but_average_3->Click += gcnew System::EventHandler(this, &MyForm::but_average_3_Click);
			// 
			// but_average_2
			// 
			this->but_average_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_average_2->Location = System::Drawing::Point(1545, 848);
			this->but_average_2->Name = L"but_average_2";
			this->but_average_2->Size = System::Drawing::Size(90, 30);
			this->but_average_2->TabIndex = 46;
			this->but_average_2->Text = L"Построить";
			this->but_average_2->UseVisualStyleBackColor = true;
			this->but_average_2->Click += gcnew System::EventHandler(this, &MyForm::but_average_2_Click);
			// 
			// but_average_1
			// 
			this->but_average_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_average_1->Location = System::Drawing::Point(1545, 797);
			this->but_average_1->Name = L"but_average_1";
			this->but_average_1->Size = System::Drawing::Size(90, 30);
			this->but_average_1->TabIndex = 45;
			this->but_average_1->Text = L"Построить";
			this->but_average_1->UseVisualStyleBackColor = true;
			this->but_average_1->Click += gcnew System::EventHandler(this, &MyForm::but_average_1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(1401, 801);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(53, 22);
			this->numericUpDown1->TabIndex = 48;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown2->Location = System::Drawing::Point(1401, 851);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(53, 22);
			this->numericUpDown2->TabIndex = 49;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown3->Location = System::Drawing::Point(1401, 908);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(53, 22);
			this->numericUpDown3->TabIndex = 50;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(1759, 741);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(95, 16);
			this->label13->TabIndex = 51;
			this->label13->Text = L"Масштаб (x, y)";
			// 
			// but_scale
			// 
			this->but_scale->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_scale->Location = System::Drawing::Point(1765, 878);
			this->but_scale->Name = L"but_scale";
			this->but_scale->Size = System::Drawing::Size(90, 30);
			this->but_scale->TabIndex = 52;
			this->but_scale->Text = L"Изменить";
			this->but_scale->UseVisualStyleBackColor = true;
			this->but_scale->Click += gcnew System::EventHandler(this, &MyForm::but_scale_Click);
			// 
			// textBox_scale_x_1
			// 
			this->textBox_scale_x_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_scale_x_1->Location = System::Drawing::Point(1754, 802);
			this->textBox_scale_x_1->Name = L"textBox_scale_x_1";
			this->textBox_scale_x_1->Size = System::Drawing::Size(50, 22);
			this->textBox_scale_x_1->TabIndex = 55;
			this->textBox_scale_x_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_scale_x_1_KeyPress);
			// 
			// textBox_scale_x_2
			// 
			this->textBox_scale_x_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_scale_x_2->Location = System::Drawing::Point(1754, 843);
			this->textBox_scale_x_2->Name = L"textBox_scale_x_2";
			this->textBox_scale_x_2->Size = System::Drawing::Size(50, 22);
			this->textBox_scale_x_2->TabIndex = 56;
			this->textBox_scale_x_2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_scale_x_2_KeyPress);
			// 
			// comboBox_average_1
			// 
			this->comboBox_average_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox_average_1->FormattingEnabled = true;
			this->comboBox_average_1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"x(t)", L"y(t)", L"z(t)", L"T(t)" });
			this->comboBox_average_1->Location = System::Drawing::Point(1471, 800);
			this->comboBox_average_1->Name = L"comboBox_average_1";
			this->comboBox_average_1->Size = System::Drawing::Size(60, 24);
			this->comboBox_average_1->TabIndex = 57;
			// 
			// comboBox_average_2
			// 
			this->comboBox_average_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox_average_2->FormattingEnabled = true;
			this->comboBox_average_2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"x(t)", L"y(t)", L"z(t)", L"T(t)" });
			this->comboBox_average_2->Location = System::Drawing::Point(1471, 852);
			this->comboBox_average_2->Name = L"comboBox_average_2";
			this->comboBox_average_2->Size = System::Drawing::Size(60, 24);
			this->comboBox_average_2->TabIndex = 58;
			// 
			// comboBox_average_3
			// 
			this->comboBox_average_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox_average_3->FormattingEnabled = true;
			this->comboBox_average_3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"x(t)", L"y(t)", L"z(t)", L"T(t)" });
			this->comboBox_average_3->Location = System::Drawing::Point(1471, 907);
			this->comboBox_average_3->Name = L"comboBox_average_3";
			this->comboBox_average_3->Size = System::Drawing::Size(60, 24);
			this->comboBox_average_3->TabIndex = 59;
			// 
			// textBox_scale_y_2
			// 
			this->textBox_scale_y_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_scale_y_2->Location = System::Drawing::Point(1817, 843);
			this->textBox_scale_y_2->Name = L"textBox_scale_y_2";
			this->textBox_scale_y_2->Size = System::Drawing::Size(50, 22);
			this->textBox_scale_y_2->TabIndex = 61;
			this->textBox_scale_y_2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_scale_y_2_KeyPress);
			// 
			// textBox_scale_y_1
			// 
			this->textBox_scale_y_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_scale_y_1->Location = System::Drawing::Point(1817, 802);
			this->textBox_scale_y_1->Name = L"textBox_scale_y_1";
			this->textBox_scale_y_1->Size = System::Drawing::Size(50, 22);
			this->textBox_scale_y_1->TabIndex = 60;
			this->textBox_scale_y_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_scale_y_1_KeyPress);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(1773, 783);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 16);
			this->label14->TabIndex = 62;
			this->label14->Text = L"x";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(1836, 783);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(14, 16);
			this->label15->TabIndex = 63;
			this->label15->Text = L"y";
			// 
			// textBox_interval_1
			// 
			this->textBox_interval_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_interval_1->Location = System::Drawing::Point(1247, 801);
			this->textBox_interval_1->Name = L"textBox_interval_1";
			this->textBox_interval_1->Size = System::Drawing::Size(30, 22);
			this->textBox_interval_1->TabIndex = 65;
			this->textBox_interval_1->Text = L"2";
			this->textBox_interval_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_interval_1_KeyPress);
			// 
			// but_interval_1
			// 
			this->but_interval_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_interval_1->Location = System::Drawing::Point(1295, 796);
			this->but_interval_1->Name = L"but_interval_1";
			this->but_interval_1->Size = System::Drawing::Size(90, 30);
			this->but_interval_1->TabIndex = 66;
			this->but_interval_1->Text = L"Изменить";
			this->but_interval_1->UseVisualStyleBackColor = true;
			this->but_interval_1->Click += gcnew System::EventHandler(this, &MyForm::but_interval_1_Click);
			// 
			// but_interval_2
			// 
			this->but_interval_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_interval_2->Location = System::Drawing::Point(1295, 848);
			this->but_interval_2->Name = L"but_interval_2";
			this->but_interval_2->Size = System::Drawing::Size(90, 30);
			this->but_interval_2->TabIndex = 68;
			this->but_interval_2->Text = L"Изменить";
			this->but_interval_2->UseVisualStyleBackColor = true;
			this->but_interval_2->Click += gcnew System::EventHandler(this, &MyForm::but_interval_2_Click);
			// 
			// textBox_interval_2
			// 
			this->textBox_interval_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_interval_2->Location = System::Drawing::Point(1247, 853);
			this->textBox_interval_2->Name = L"textBox_interval_2";
			this->textBox_interval_2->Size = System::Drawing::Size(30, 22);
			this->textBox_interval_2->TabIndex = 67;
			this->textBox_interval_2->Text = L"2";
			this->textBox_interval_2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_interval_2_KeyPress);
			// 
			// but_interval_3
			// 
			this->but_interval_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_interval_3->Location = System::Drawing::Point(1295, 903);
			this->but_interval_3->Name = L"but_interval_3";
			this->but_interval_3->Size = System::Drawing::Size(90, 30);
			this->but_interval_3->TabIndex = 70;
			this->but_interval_3->Text = L"Изменить";
			this->but_interval_3->UseVisualStyleBackColor = true;
			this->but_interval_3->Click += gcnew System::EventHandler(this, &MyForm::but_interval_3_Click);
			// 
			// textBox_interval_3
			// 
			this->textBox_interval_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_interval_3->Location = System::Drawing::Point(1247, 908);
			this->textBox_interval_3->Name = L"textBox_interval_3";
			this->textBox_interval_3->Size = System::Drawing::Size(30, 22);
			this->textBox_interval_3->TabIndex = 69;
			this->textBox_interval_3->Text = L"2";
			this->textBox_interval_3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_interval_3_KeyPress);
			// 
			// but_clear_avg_1
			// 
			this->but_clear_avg_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_clear_avg_1->Location = System::Drawing::Point(1641, 796);
			this->but_clear_avg_1->Name = L"but_clear_avg_1";
			this->but_clear_avg_1->Size = System::Drawing::Size(90, 30);
			this->but_clear_avg_1->TabIndex = 71;
			this->but_clear_avg_1->Text = L"Отменить";
			this->but_clear_avg_1->UseVisualStyleBackColor = true;
			this->but_clear_avg_1->Click += gcnew System::EventHandler(this, &MyForm::but_clear_avg_1_Click);
			// 
			// but_clear_avg_2
			// 
			this->but_clear_avg_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_clear_avg_2->Location = System::Drawing::Point(1641, 848);
			this->but_clear_avg_2->Name = L"but_clear_avg_2";
			this->but_clear_avg_2->Size = System::Drawing::Size(90, 30);
			this->but_clear_avg_2->TabIndex = 72;
			this->but_clear_avg_2->Text = L"Отменить";
			this->but_clear_avg_2->UseVisualStyleBackColor = true;
			this->but_clear_avg_2->Click += gcnew System::EventHandler(this, &MyForm::but_clear_avg_2_Click);
			// 
			// but_clear_avg_3
			// 
			this->but_clear_avg_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_clear_avg_3->Location = System::Drawing::Point(1641, 903);
			this->but_clear_avg_3->Name = L"but_clear_avg_3";
			this->but_clear_avg_3->Size = System::Drawing::Size(90, 30);
			this->but_clear_avg_3->TabIndex = 73;
			this->but_clear_avg_3->Text = L"Отменить";
			this->but_clear_avg_3->UseVisualStyleBackColor = true;
			this->but_clear_avg_3->Click += gcnew System::EventHandler(this, &MyForm::but_clear_avg_3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->but_clear_avg_3);
			this->Controls->Add(this->but_clear_avg_2);
			this->Controls->Add(this->but_clear_avg_1);
			this->Controls->Add(this->but_interval_3);
			this->Controls->Add(this->textBox_interval_3);
			this->Controls->Add(this->but_interval_2);
			this->Controls->Add(this->textBox_interval_2);
			this->Controls->Add(this->but_interval_1);
			this->Controls->Add(this->textBox_interval_1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBox_scale_y_2);
			this->Controls->Add(this->textBox_scale_y_1);
			this->Controls->Add(this->comboBox_average_3);
			this->Controls->Add(this->comboBox_average_2);
			this->Controls->Add(this->comboBox_average_1);
			this->Controls->Add(this->textBox_scale_x_2);
			this->Controls->Add(this->textBox_scale_x_1);
			this->Controls->Add(this->but_scale);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->but_average_3);
			this->Controls->Add(this->but_average_2);
			this->Controls->Add(this->but_average_1);
			this->Controls->Add(this->but_T_3);
			this->Controls->Add(this->but_T_2);
			this->Controls->Add(this->but_T_1);
			this->Controls->Add(this->but_z_3);
			this->Controls->Add(this->but_z_2);
			this->Controls->Add(this->but_z_1);
			this->Controls->Add(this->but_y_3);
			this->Controls->Add(this->but_y_2);
			this->Controls->Add(this->but_y_1);
			this->Controls->Add(this->but_x_3);
			this->Controls->Add(this->but_x_2);
			this->Controls->Add(this->but_x_1);
			this->Controls->Add(this->but_selectfile_3);
			this->Controls->Add(this->but_selectfile_2);
			this->Controls->Add(this->but_selectfile_1);
			this->Controls->Add(this->but_close);
			this->Controls->Add(this->but_clear);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label_freq_3);
			this->Controls->Add(this->label_freq_2);
			this->Controls->Add(this->label_freq_1);
			this->Controls->Add(this->label_date_3);
			this->Controls->Add(this->label_date_2);
			this->Controls->Add(this->label_date_1);
			this->Controls->Add(this->textBox_file_3);
			this->Controls->Add(this->textBox_file_2);
			this->Controls->Add(this->textBox_file_1);
			this->Controls->Add(this->label_chart_3);
			this->Controls->Add(this->label_chart_2);
			this->Controls->Add(this->label_chart_1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ResLab";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Кнопка очистки полей графика
	private: System::Void but_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 14; i++)
		{
			this->chart1->Series[i]->Points->Clear(); // Очистка полей графика
			this->but_x_1->BackColor = Color::LightGray;
			this->but_y_1->BackColor = Color::LightGray;
			this->but_z_1->BackColor = Color::LightGray;
			this->but_T_1->BackColor = Color::LightGray;
			this->but_x_2->BackColor = Color::LightGray;
			this->but_y_2->BackColor = Color::LightGray;
			this->but_z_2->BackColor = Color::LightGray;
			this->but_T_2->BackColor = Color::LightGray;
			this->but_x_3->BackColor = Color::LightGray;
			this->but_y_3->BackColor = Color::LightGray;
			this->but_z_3->BackColor = Color::LightGray;
			this->but_T_3->BackColor = Color::LightGray;
		}
	}

	// Кнопка закрытия приложения
	private: System::Void but_close_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit(); //Закрытие для всего приложения
		//Close();           //Закрытие для одной формы
	}

	// Кнопка добавить график 1
	private: System::Void but_selectfile_1_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ FileName = "";  // Имя файла 1
		string FileNameNew;     // Имя файла 1
		string line;            // Строка в файле
		int line1, line2;       // Переменные для определения частоты измерений
		string time_hour;       // Переменная для определения часа
		string time_minute;     // Переменная для определения минуты
		string time_second;     // Переменная для определения секунд
		string date_year;       // Переменная для определения года
		string date_month;      // Переменная для определения месяца
		string date_day;        // Переменная для определения дня
		string time1;           // Переменная для общего времени
		double x1 = 0;          // Вспомогательные переменные
		double y1 = 0;
		double z1 = 0;
		double T1 = 0;
		double countline1 = 0;  // Счётчик строк для первого прохода
		double countline2 = 0;  // Счётчик строк для второго прохода
		int countX = 0;         // Счётчик для вывода на ось Х

		this->openFileDialog1->Filter = "text files(*.txt)|*.txt"; // Фильтр на выбор текстовых файлов

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			FileName = openFileDialog1->FileName;                        // Присвоение имени файла
			FileNameNew = msclr::interop::marshal_as<string>(FileName); // Конвертация из System::String^ в std::string
		}

		ifstream fin1_1(FileNameNew);   // Чтение из файла

		if (fin1_1.is_open())            // Проверка на открытие файла
		{
			vector_x_1.clear(); // Очистка векторов, которые были записаны ранее
			vector_y_1.clear();
			vector_z_1.clear();
			vector_T_1.clear();
			vector_time_1.clear();
			countfreq_1 = 0;

			while (!fin1_1.eof())        // Пока не конце файла
			{
				getline(fin1_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline1 == 0) // Подсчёт количество измерений в секунду (Гц)
					{
						line1 = stoi(line.substr(6, 6));
					}
					line2 = stoi(line.substr(6, 6));
					if (line1 == line2)
					{
						label_freq_1->Text = (countfreq_1 + 2).ToString();
						freq1 = (1 / (countfreq_1 + 2));
						countfreq_1++;
					}
					countline1++;
				}
				else
				{
					MessageBox::Show(this, "Файл открыт, но в файле присутствовала пустая строка.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
		else
		{
			MessageBox::Show(this, "Файл не был открыт", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		fin1_1.close(); // Закрытие потока

		ifstream fin2_1(FileNameNew);    // Открытие потока для чтения

		if (fin2_1.is_open())            // Чтение из файла
		{
			while (!fin2_1.eof())        // Пока не конец файла
			{
				getline(fin2_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline2 == 0) // Считывание даты создания файла
					{
						date_year = line.substr(0, 2);
						date_month = line.substr(2, 2);
						date_day = line.substr(4, 2);
						time_hour = line.substr(6, 2);
						time_minute = line.substr(8, 2);
						time_second = line.substr(10, 2);
					}
					time_hour = line.substr(6, 2);   // Присвоение даты в переменные
					time_minute = line.substr(8, 2);
					time_second = line.substr(10, 2);
					time1 = time_hour + ":" + time_minute + ":" + time_second + " (" + to_string(countX) + ")"; // Общая дата
					vector_time_1.push_back(time1);

					x1 = stod(line.substr(22, 5)); // Запись данных в вектор X
					vector_x_1.push_back(x1);

					y1 = stod(line.substr(33, 5)); // Запись данных в вектор Y
					vector_y_1.push_back(y1);

					z1 = stod(line.substr(44, 5)); // Запись данных в вектор Z
					vector_z_1.push_back(z1);

					T1 = stod(line.substr(55, 5)); // Запись данных в вектор T
					vector_T_1.push_back(T1);

					countline2++;
					countX++;
				}
			}
		}

		fin2_1.close(); // Закрытие потока
		textBox_file_1->Text = gcnew System::String(FileNameNew.c_str()); // Вывод пути к файлу
		string date_full; // Переменная полной даты для вывода
		date_full = date_day + "." + date_month + "." + date_year;    // Полная дата
		label_date_1->Text = gcnew System::String(date_full.c_str()); // Вывод полной даты
		count_avg_1 = countX;

	}

	// Кнопка график 1 x(t)
	private: System::Void but_x_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_x_1 == 0) 
		{
			this->but_x_1->BackColor = Color::White;
			this->chart1->Series[0]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_x_1.size(); i++)
			{
				this->chart1->Series[0]->Points->AddXY(i + 1, vector_x_1[i]); // Построение графика
			}

			for (int i = 0; i < vector_x_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
			{
				String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
				CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
				startOffset = startOffset + 2 * countfreq_1;
				endOffset = endOffset + 2 * countfreq_1;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей

			countclear_x_1 = 1;
		}
		else
		{
			this->but_x_1->BackColor = Color::LightGray;
			this->chart1->Series[0]->Points->Clear(); // Очистка старого графика
			countclear_x_1 = 0;
		}

	}

	// Кнопка график 1 y(t)
	private: System::Void but_y_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_y_1 == 0)
		{
			this->but_y_1->BackColor = Color::White;
			this->chart1->Series[1]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_y_1.size(); i++)
			{
				this->chart1->Series[1]->Points->AddXY(i + 1, vector_y_1[i]); // Построение графика
			}

			for (int i = 0; i < vector_y_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
			{
				String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
				CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
				startOffset = startOffset + 2 * countfreq_1;
				endOffset = endOffset + 2 * countfreq_1;
			}
			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей

			countclear_y_1 = 1;
		}
		else
		{
			this->but_y_1->BackColor = Color::LightGray;
			this->chart1->Series[1]->Points->Clear(); // Очистка старого графика
			countclear_y_1 = 0;
		}

	}

	// Кнопка график 1 z(t)
	private: System::Void but_z_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_z_1 == 0)
		{
			this->but_z_1->BackColor = Color::White;
			this->chart1->Series[2]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_z_1.size(); i++)
			{
				this->chart1->Series[2]->Points->AddXY(i + 1, vector_z_1[i]); // Построение графика
			}

			for (int i = 0; i < vector_z_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
			{
				String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
				CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
				startOffset = startOffset + 2 * countfreq_1;
				endOffset = endOffset + 2 * countfreq_1;
			}
			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей

			countclear_z_1 = 1;
		}
		else
		{
			this->but_z_1->BackColor = Color::LightGray;
			this->chart1->Series[2]->Points->Clear(); // Очистка старого графика
			countclear_z_1 = 0;
		}

	}

	// Кнопка график 1 T(t)
	private: System::Void but_T_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_T_1 == 0)
		{
			this->but_T_1->BackColor = Color::White;
			this->chart1->Series[3]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_T_1.size(); i++)
			{
				this->chart1->Series[3]->Points->AddXY(i + 1, vector_T_1[i]); // Построение графика
			}

			for (int i = 0; i < vector_T_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
			{
				String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
				CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
				startOffset = startOffset + 2 * countfreq_1;
				endOffset = endOffset + 2 * countfreq_1;
			}
			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей

			countclear_T_1 = 1;
		}
		else
		{
			this->but_T_1->BackColor = Color::LightGray;
			this->chart1->Series[3]->Points->Clear(); // Очистка старого графика
			countclear_T_1 = 0;
		}

	}

	// Кнопка интервала 1
	private: System::Void but_interval_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int avg;
		if (textBox_interval_1->Text != "")
		{
			avg = Convert::ToInt32(textBox_interval_1->Text);
			if (avg > 0)
			{
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Clear();
				for (int i = 0; i < vector_x_1.size(); i = i + (avg * countfreq_1)) // Замена надписей по оси Х
				{
					String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
					CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
					this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
					startOffset = startOffset + (avg * countfreq_1);
					endOffset = endOffset + (avg * countfreq_1);
				}
				this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
				this->chart1->ChartAreas[0]->AxisX->Interval = (avg * countfreq_1); // Масштабирование и подписей
			}
			else
			{
				MessageBox::Show(this, "Введите значение больше 0", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show(this, "Введите значение", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Кнопка скользящего среднего 1
	private: System::Void but_average_1_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int index = 0;   // Индекс для выбора
		int numeric = 0; // Коэффициент для скользящего среднего
		int div = 0;     // Переменная для деления
		double sum = 0;  // Переменная для суммы
		double avg_new = 0; // Среднее выборочное значение
		int k = 0;          // Дополнительный индекс
		index = comboBox_average_1->SelectedIndex;
		numeric = Convert::ToInt32(numericUpDown1->Text);

		if ((numeric == 0) || (index < 0))
		{
			MessageBox::Show(this, "Заполните поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else 
		{
			this->chart1->Series[12]->Points->Clear(); // Очистка старого графика
			div = count_avg_1 % numeric; // Проверка на деление без остатка
			if (div == 0)
			{
				if (index == 0) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_1 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_x_1[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_1.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_1.size(); i++)
					{
						this->chart1->Series[12]->Points->AddXY(i + 1, vector_avg_1[i]); // Построение графика
					}

					for (int i = 0; i < vector_x_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
					{
						String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
						CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
						startOffset = startOffset + 2 * countfreq_1;
						endOffset = endOffset + 2 * countfreq_1;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей
				}
				if (index == 1) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_1 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_y_1[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_1.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_1.size(); i++)
					{
						this->chart1->Series[12]->Points->AddXY(i + 1, vector_avg_1[i]); // Построение графика
					}

					for (int i = 0; i < vector_y_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
					{
						String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
						CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
						startOffset = startOffset + 2 * countfreq_1;
						endOffset = endOffset + 2 * countfreq_1;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей
				}
				if (index == 2) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_1 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_z_1[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_1.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_1.size(); i++)
					{
						this->chart1->Series[12]->Points->AddXY(i + 1, vector_avg_1[i]); // Построение графика
					}

					for (int i = 0; i < vector_z_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
					{
						String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
						CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
						startOffset = startOffset + 2 * countfreq_1;
						endOffset = endOffset + 2 * countfreq_1;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей
				}
				if (index == 3) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_1 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_T_1[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_1.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_1.size(); i++)
					{
						this->chart1->Series[12]->Points->AddXY(i + 1, vector_avg_1[i]); // Построение графика
					}

					for (int i = 0; i < vector_T_1.size(); i = i + 2 * countfreq_1) // Замена надписей по оси Х
					{
						String^ text_label_1 = gcnew System::String(vector_time_1[i].c_str());
						CustomLabel^ label_date_1 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_1, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_1);
						startOffset = startOffset + 2 * countfreq_1;
						endOffset = endOffset + 2 * countfreq_1;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_1; // Масштабирование и подписей
				}
			}
			else 
			{
				MessageBox::Show(this, "Заполните верным значением.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		vector_avg_1.clear(); // Очистка вектора
	}

	// Очистка скользящего среднего 1
	private: System::Void but_clear_avg_1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->chart1->Series[12]->Points->Clear(); // Очистка старого графика
	}

	// Кнопка добавить график 2
	private: System::Void but_selectfile_2_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ FileName = "";  // Имя файла 1
		string FileNameNew;     // Имя файла 1
		string line;            // Строка в файле
		int line1, line2;       // Переменные для определения частоты измерений
		string time_hour;       // Переменная для определения часа
		string time_minute;     // Переменная для определения минуты
		string time_second;     // Переменная для определения секунд
		string date_year;       // Переменная для определения года
		string date_month;      // Переменная для определения месяца
		string date_day;        // Переменная для определения дня
		string time1;           // Переменная для общего времени
		double x1 = 0;          // Вспомогательные переменные
		double y1 = 0;
		double z1 = 0;
		double T1 = 0;
		double countline1 = 0;  // Счётчик строк для первого прохода
		double countline2 = 0;  // Счётчик строк для второго прохода
		int countX = 0;         // Счётчик для вывода на ось Х

		this->openFileDialog1->Filter = "text files(*.txt)|*.txt"; // Фильтр на выбор текстовых файлов

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			FileName = openFileDialog1->FileName;                        // Присвоение имени файла
			FileNameNew = msclr::interop::marshal_as<string>(FileName); // Конвертация из System::String^ в std::string
		}

		ifstream fin1_1(FileNameNew);   // Чтение из файла

		if (fin1_1.is_open())            // Проверка на открытие файла
		{
			vector_x_2.clear(); // Очистка векторов, которые были записаны ранее
			vector_y_2.clear();
			vector_z_2.clear();
			vector_T_2.clear();
			vector_time_2.clear();
			countfreq_2 = 0;

			while (!fin1_1.eof())        // Пока не конце файла
			{
				getline(fin1_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline1 == 0) // Подсчёт количество измерений в секунду (Гц)
					{
						line1 = stoi(line.substr(6, 6));
					}
					line2 = stoi(line.substr(6, 6));
					if (line1 == line2)
					{
						label_freq_2->Text = (countfreq_2 + 2).ToString();
						freq2 = (1 / (countfreq_2 + 2));
						countfreq_2++;
					}
					countline1++;
				}
				else
				{
					MessageBox::Show(this, "Файл открыт, но в файле присутствовала пустая строка.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
		else
		{
			MessageBox::Show(this, "Файл не был открыт", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		fin1_1.close(); // Закрытие потока

		ifstream fin2_1(FileNameNew);    // Открытие потока для чтения

		if (fin2_1.is_open())            // Чтение из файла
		{
			while (!fin2_1.eof())        // Пока не конец файла
			{
				getline(fin2_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline2 == 0) // Считывание даты создания файла
					{
						date_year = line.substr(0, 2);
						date_month = line.substr(2, 2);
						date_day = line.substr(4, 2);
						time_hour = line.substr(6, 2);
						time_minute = line.substr(8, 2);
						time_second = line.substr(10, 2);
					}
					time_hour = line.substr(6, 2);   // Присвоение даты в переменные
					time_minute = line.substr(8, 2);
					time_second = line.substr(10, 2);
					time1 = time_hour + ":" + time_minute + ":" + time_second + " (" + to_string(countX) + ")"; // Общая дата
					vector_time_2.push_back(time1);

					x1 = stod(line.substr(22, 5)); // Запись данных в вектор X
					vector_x_2.push_back(x1);

					y1 = stod(line.substr(33, 5)); // Запись данных в вектор Y
					vector_y_2.push_back(y1);

					z1 = stod(line.substr(44, 5)); // Запись данных в вектор Z
					vector_z_2.push_back(z1);

					T1 = stod(line.substr(55, 5)); // Запись данных в вектор T
					vector_T_2.push_back(T1);

					countline2++;
					countX++;
				}
			}
		}

		fin2_1.close(); // Закрытие потока
		textBox_file_2->Text = gcnew System::String(FileNameNew.c_str()); // Вывод пути к файлу
		string date_full; // Переменная полной даты для вывода
		date_full = date_day + "." + date_month + "." + date_year;    // Полная дата
		label_date_2->Text = gcnew System::String(date_full.c_str()); // Вывод полной даты
		count_avg_2 = countX;
	}

	// Кнопка график 2 x(t)
	private: System::Void but_x_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_x_2 == 0)
		{
			this->but_x_2->BackColor = Color::White;
			this->chart1->Series[4]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_x_2.size(); i++)
			{
				this->chart1->Series[4]->Points->AddXY(i + 1, vector_x_2[i]); // Построение графика
			}

			for (int i = 0; i < vector_x_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
			{
				String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
				CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
				startOffset = startOffset + 2 * countfreq_2;
				endOffset = endOffset + 2 * countfreq_2;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей

			countclear_x_2 = 1;
		}
		else
		{
			this->but_x_2->BackColor = Color::LightGray;
			this->chart1->Series[4]->Points->Clear(); // Очистка старого графика
			countclear_x_2 = 0;
		}
	}

	// Кнопка график 2 y(t)
	private: System::Void but_y_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_y_2 == 0)
		{
			this->but_y_2->BackColor = Color::White;
			this->chart1->Series[5]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_y_2.size(); i++)
			{
				this->chart1->Series[5]->Points->AddXY(i + 1, vector_y_2[i]); // Построение графика
			}

			for (int i = 0; i < vector_y_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
			{
				String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
				CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
				startOffset = startOffset + 2 * countfreq_2;
				endOffset = endOffset + 2 * countfreq_2;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей

			countclear_y_2 = 1;
		}
		else
		{
			this->but_y_2->BackColor = Color::LightGray;
			this->chart1->Series[5]->Points->Clear(); // Очистка старого графика
			countclear_y_2 = 0;
		}
	}

	// Кнопка график 2 z(t)
	private: System::Void but_z_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_z_2 == 0)
		{
			this->but_z_2->BackColor = Color::White;
			this->chart1->Series[6]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_z_2.size(); i++)
			{
				this->chart1->Series[6]->Points->AddXY(i + 1, vector_z_2[i]); // Построение графика
			}

			for (int i = 0; i < vector_z_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
			{
				String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
				CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
				startOffset = startOffset + 2 * countfreq_2;
				endOffset = endOffset + 2 * countfreq_2;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей

			countclear_z_2 = 1;
		}
		else
		{
			this->but_z_2->BackColor = Color::LightGray;
			this->chart1->Series[6]->Points->Clear(); // Очистка старого графика
			countclear_z_2 = 0;
		}
	}

	// Кнопка график 2 T(t)
	private: System::Void but_T_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_T_2 == 0)
		{
			this->but_T_2->BackColor = Color::White;
			this->chart1->Series[7]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_T_2.size(); i++)
			{
				this->chart1->Series[7]->Points->AddXY(i + 1, vector_T_2[i]); // Построение графика
			}

			for (int i = 0; i < vector_T_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
			{
				String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
				CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
				startOffset = startOffset + 2 * countfreq_2;
				endOffset = endOffset + 2 * countfreq_2;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей

			countclear_T_2 = 1;
		}
		else
		{
			this->but_T_2->BackColor = Color::LightGray;
			this->chart1->Series[7]->Points->Clear(); // Очистка старого графика
			countclear_T_2 = 0;
		}
	}

	// Кнопка интервала 2
	private: System::Void but_interval_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int avg;
		if (textBox_interval_2->Text != "")
		{
			avg = Convert::ToInt32(textBox_interval_2->Text);
			if (avg > 0)
			{
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Clear();
				for (int i = 0; i < vector_x_2.size(); i = i + (avg * countfreq_2)) // Замена надписей по оси Х
				{
					String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
					CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
					this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
					startOffset = startOffset + (avg * countfreq_2);
					endOffset = endOffset + (avg * countfreq_2);
				}
				this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
				this->chart1->ChartAreas[0]->AxisX->Interval = (avg * countfreq_2); // Масштабирование и подписей
			}
			else
			{
				MessageBox::Show(this, "Введите значение больше 0", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show(this, "Введите значение", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Кнопка скользящего среднего 2
	private: System::Void but_average_2_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int index = 0;   // Индекс для выбора
		int numeric = 0; // Коэффициент для скользящего среднего
		int div = 0;     // Переменная для деления
		double sum = 0;  // Переменная для суммы
		double avg_new = 0; // Среднее выборочное значение
		int k = 0;          // Дополнительный индекс
		index = comboBox_average_2->SelectedIndex;
		numeric = Convert::ToInt32(numericUpDown2->Text);

		if ((numeric == 0) || (index < 0))
		{
			MessageBox::Show(this, "Заполните поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			this->chart1->Series[13]->Points->Clear(); // Очистка старого графика
			div = count_avg_2 % numeric; // Проверка на деление без остатка
			if (div == 0)
			{
				if (index == 0) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_2 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_x_2[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_2.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_2.size(); i++)
					{
						this->chart1->Series[13]->Points->AddXY(i + 1, vector_avg_2[i]); // Построение графика
					}

					for (int i = 0; i < vector_x_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
					{
						String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
						CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
						startOffset = startOffset + 2 * countfreq_2;
						endOffset = endOffset + 2 * countfreq_2;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей
				}
				if (index == 1) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_2 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_y_2[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_2.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_2.size(); i++)
					{
						this->chart1->Series[13]->Points->AddXY(i + 1, vector_avg_2[i]); // Построение графика
					}

					for (int i = 0; i < vector_y_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
					{
						String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
						CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
						startOffset = startOffset + 2 * countfreq_2;
						endOffset = endOffset + 2 * countfreq_2;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей
				}
				if (index == 2) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_2 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_z_2[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_2.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_2.size(); i++)
					{
						this->chart1->Series[13]->Points->AddXY(i + 1, vector_avg_2[i]); // Построение графика
					}

					for (int i = 0; i < vector_z_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
					{
						String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
						CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
						startOffset = startOffset + 2 * countfreq_2;
						endOffset = endOffset + 2 * countfreq_2;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей
				}
				if (index == 3) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_2 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_T_2[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_2.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_2.size(); i++)
					{
						this->chart1->Series[13]->Points->AddXY(i + 1, vector_avg_2[i]); // Построение графика
					}

					for (int i = 0; i < vector_T_2.size(); i = i + 2 * countfreq_2) // Замена надписей по оси Х
					{
						String^ text_label_2 = gcnew System::String(vector_time_2[i].c_str());
						CustomLabel^ label_date_2 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_2, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_2);
						startOffset = startOffset + 2 * countfreq_2;
						endOffset = endOffset + 2 * countfreq_2;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_2; // Масштабирование и подписей
				}
			}
			else
			{
				MessageBox::Show(this, "Заполните верным значением.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		vector_avg_2.clear(); // Очистка вектора
	}

	// Очистка скользящего среднего 2
	private: System::Void but_clear_avg_2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->chart1->Series[13]->Points->Clear(); // Очистка старого графика
	}

	// Кнопка добавить график 3
	private: System::Void but_selectfile_3_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ FileName = "";  // Имя файла 1
		string FileNameNew;     // Имя файла 1
		string line;            // Строка в файле
		int line1, line2;       // Переменные для определения частоты измерений
		string time_hour;       // Переменная для определения часа
		string time_minute;     // Переменная для определения минуты
		string time_second;     // Переменная для определения секунд
		string date_year;       // Переменная для определения года
		string date_month;      // Переменная для определения месяца
		string date_day;        // Переменная для определения дня
		string time1;           // Переменная для общего времени
		double x1 = 0;          // Вспомогательные переменные
		double y1 = 0;
		double z1 = 0;
		double T1 = 0;
		double countline1 = 0;  // Счётчик строк для первого прохода
		double countline2 = 0;  // Счётчик строк для второго прохода
		int countX = 0;         // Счётчик для вывода на ось Х

		this->openFileDialog1->Filter = "text files(*.txt)|*.txt"; // Фильтр на выбор текстовых файлов

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			FileName = openFileDialog1->FileName;                        // Присвоение имени файла
			FileNameNew = msclr::interop::marshal_as<string>(FileName); // Конвертация из System::String^ в std::string
		}

		ifstream fin1_1(FileNameNew);   // Чтение из файла

		if (fin1_1.is_open())            // Проверка на открытие файла
		{
			vector_x_3.clear(); // Очистка векторов, которые были записаны ранее
			vector_y_3.clear();
			vector_z_3.clear();
			vector_T_3.clear();
			vector_time_3.clear();
			countfreq_3 = 0;

			while (!fin1_1.eof())        // Пока не конце файла
			{
				getline(fin1_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline1 == 0) // Подсчёт количество измерений в секунду (Гц)
					{
						line1 = stoi(line.substr(6, 6));
					}
					line2 = stoi(line.substr(6, 6));
					if (line1 == line2)
					{
						label_freq_3->Text = (countfreq_3 + 2).ToString();
						freq3 = (1 / (countfreq_3 + 2));
						countfreq_3++;
					}
					countline1++;
				}
				else
				{
					MessageBox::Show(this, "Файл открыт, но в файле присутствовала пустая строка.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
		else
		{
			MessageBox::Show(this, "Файл не был открыт", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		fin1_1.close(); // Закрытие потока

		ifstream fin2_1(FileNameNew);    // Открытие потока для чтения

		if (fin2_1.is_open())            // Чтение из файла
		{
			while (!fin2_1.eof())        // Пока не конец файла
			{
				getline(fin2_1, line);   // Построчное чтение файла
				if (line.length() != 0)  // Проверка на пустую строку
				{
					if (countline2 == 0) // Считывание даты создания файла
					{
						date_year = line.substr(0, 2);
						date_month = line.substr(2, 2);
						date_day = line.substr(4, 2);
						time_hour = line.substr(6, 2);
						time_minute = line.substr(8, 2);
						time_second = line.substr(10, 2);
					}
					time_hour = line.substr(6, 2);   // Присвоение даты в переменные
					time_minute = line.substr(8, 2);
					time_second = line.substr(10, 2);
					time1 = time_hour + ":" + time_minute + ":" + time_second + " (" + to_string(countX) + ")"; // Общая дата
					vector_time_3.push_back(time1);

					x1 = stod(line.substr(22, 5)); // Запись данных в вектор X
					vector_x_3.push_back(x1);

					y1 = stod(line.substr(33, 5)); // Запись данных в вектор Y
					vector_y_3.push_back(y1);

					z1 = stod(line.substr(44, 5)); // Запись данных в вектор Z
					vector_z_3.push_back(z1);

					T1 = stod(line.substr(55, 5)); // Запись данных в вектор T
					vector_T_3.push_back(T1);

					countline2++;
					countX++;
				}
			}
		}

		fin2_1.close(); // Закрытие потока
		textBox_file_3->Text = gcnew System::String(FileNameNew.c_str()); // Вывод пути к файлу
		string date_full; // Переменная полной даты для вывода
		date_full = date_day + "." + date_month + "." + date_year;    // Полная дата
		label_date_3->Text = gcnew System::String(date_full.c_str()); // Вывод полной даты
		count_avg_3 = countX;
	}

	// Кнопка график 3 x(t)
	private: System::Void but_x_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_x_3 == 0)
		{
			this->but_x_3->BackColor = Color::White;
			this->chart1->Series[8]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_x_3.size(); i++)
			{
				this->chart1->Series[8]->Points->AddXY(i + 1, vector_x_3[i]); // Построение графика
			}

			for (int i = 0; i < vector_x_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
			{
				String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
				CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
				startOffset = startOffset + 2 * countfreq_3;
				endOffset = endOffset + 2 * countfreq_3;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей

			countclear_x_3 = 1;
		}
		else
		{
			this->but_x_3->BackColor = Color::LightGray;
			this->chart1->Series[8]->Points->Clear(); // Очистка старого графика
			countclear_x_3 = 0;
		}
	}

	// Кнопка график 3 y(t)
	private: System::Void but_y_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_y_3 == 0)
		{
			this->but_y_3->BackColor = Color::White;
			this->chart1->Series[9]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_y_3.size(); i++)
			{
				this->chart1->Series[9]->Points->AddXY(i + 1, vector_y_3[i]); // Построение графика
			}

			for (int i = 0; i < vector_y_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
			{
				String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
				CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
				startOffset = startOffset + 2 * countfreq_3;
				endOffset = endOffset + 2 * countfreq_3;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей

			countclear_y_3 = 1;
		}
		else
		{
			this->but_y_3->BackColor = Color::LightGray;
			this->chart1->Series[9]->Points->Clear(); // Очистка старого графика
			countclear_y_3 = 0;
		}
	}

	// Кнопка график 3 z(t)
	private: System::Void but_z_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_z_3 == 0)
		{
			this->but_z_3->BackColor = Color::White;
			this->chart1->Series[10]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_z_3.size(); i++)
			{
				this->chart1->Series[10]->Points->AddXY(i + 1, vector_z_3[i]); // Построение графика
			}

			for (int i = 0; i < vector_z_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
			{
				String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
				CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
				startOffset = startOffset + 2 * countfreq_3;
				endOffset = endOffset + 2 * countfreq_3;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей

			countclear_z_3 = 1;
		}
		else
		{
			this->but_z_3->BackColor = Color::LightGray;
			this->chart1->Series[10]->Points->Clear(); // Очистка старого графика
			countclear_z_3 = 0;
		}
	}

	// Кнопка график 3 T(t)
	private: System::Void but_T_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;

		if (countclear_T_3 == 0)
		{
			this->but_T_3->BackColor = Color::White;
			this->chart1->Series[11]->Points->Clear(); // Очистка старого графика
			for (int i = 0; i < vector_T_3.size(); i++)
			{
				this->chart1->Series[11]->Points->AddXY(i + 1, vector_T_3[i]); // Построение графика
			}

			for (int i = 0; i < vector_T_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
			{
				String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
				CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
				startOffset = startOffset + 2 * countfreq_3;
				endOffset = endOffset + 2 * countfreq_3;
			}

			this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
			this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей

			countclear_T_3 = 1;
		}
		else
		{
			this->but_T_3->BackColor = Color::LightGray;
			this->chart1->Series[11]->Points->Clear(); // Очистка старого графика
			countclear_T_3 = 0;
		}
	}

	// Кнопка интервала 3
	private: System::Void but_interval_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int avg;
		if (textBox_interval_3->Text != "")
		{
			avg = Convert::ToInt32(textBox_interval_3->Text);
			if (avg > 0) 
			{
				this->chart1->ChartAreas[0]->AxisX->CustomLabels->Clear();
				for (int i = 0; i < vector_x_3.size(); i = i + (avg * countfreq_3)) // Замена надписей по оси Х
				{
					String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
					CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
					this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
					startOffset = startOffset + (avg * countfreq_3);
					endOffset = endOffset + (avg * countfreq_3);
				}
				this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
				this->chart1->ChartAreas[0]->AxisX->Interval = (avg * countfreq_3); // Масштабирование и подписей
			}
			else
			{
				MessageBox::Show(this, "Введите значение больше 0", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else 
		{
			MessageBox::Show(this, "Введите значение", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}

	// Кнопка скользяшего среднего 3
	private: System::Void but_average_3_Click(System::Object^ sender, System::EventArgs^ e) {

		double startOffset = -2; // Для масштабирования
		double endOffset = 2;
		int index = 0;   // Индекс для выбора
		int numeric = 0; // Коэффициент для скользящего среднего
		int div = 0;     // Переменная для деления
		double sum = 0;  // Переменная для суммы
		double avg_new = 0; // Среднее выборочное значение
		int k = 0;          // Дополнительный индекс
		index = comboBox_average_3->SelectedIndex;
		numeric = Convert::ToInt32(numericUpDown3->Text);

		if ((numeric == 0) || (index < 0))
		{
			MessageBox::Show(this, "Заполните поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			this->chart1->Series[14]->Points->Clear(); // Очистка старого графика
			div = count_avg_3 % numeric; // Проверка на деление без остатка
			if (div == 0)
			{
				if (index == 0) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_3 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_x_3[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_3.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_3.size(); i++)
					{
						this->chart1->Series[14]->Points->AddXY(i + 1, vector_avg_3[i]); // Построение графика
					}

					for (int i = 0; i < vector_x_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
					{
						String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
						CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
						startOffset = startOffset + 2 * countfreq_3;
						endOffset = endOffset + 2 * countfreq_3;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей
				}
				if (index == 1) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_3 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_y_3[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_3.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_3.size(); i++)
					{
						this->chart1->Series[14]->Points->AddXY(i + 1, vector_avg_3[i]); // Построение графика
					}

					for (int i = 0; i < vector_y_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
					{
						String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
						CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
						startOffset = startOffset + 2 * countfreq_3;
						endOffset = endOffset + 2 * countfreq_3;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей
				}
				if (index == 2) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_3 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_z_3[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_3.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_3.size(); i++)
					{
						this->chart1->Series[14]->Points->AddXY(i + 1, vector_avg_3[i]); // Построение графика
					}

					for (int i = 0; i < vector_z_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
					{
						String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
						CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
						startOffset = startOffset + 2 * countfreq_3;
						endOffset = endOffset + 2 * countfreq_3;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей
				}
				if (index == 3) // Проверка на выбранный график из списка
				{
					for (int i = 0; i < (count_avg_3 - numeric + 1); i++) // Цикл на n-k+1 значения для новых полей усреднённого вектора
					{
						for (int j = 0; j < numeric; j++) // Подсчёт суммы
						{
							sum = sum + vector_T_3[k];
							k++;
						}
						avg_new = sum / numeric; // Получение усреднённого значения
						vector_avg_3.push_back(avg_new); // Запись в вектор
						sum = 0;     // Сброс суммы
						avg_new = 0; // Сброс усреднённого значения
						k = i;       // Сдвиг индекса для вложенного цикла
					}

					for (int i = 0; i < vector_avg_3.size(); i++)
					{
						this->chart1->Series[14]->Points->AddXY(i + 1, vector_avg_3[i]); // Построение графика
					}

					for (int i = 0; i < vector_T_3.size(); i = i + 2 * countfreq_3) // Замена надписей по оси Х
					{
						String^ text_label_3 = gcnew System::String(vector_time_3[i].c_str());
						CustomLabel^ label_date_3 = gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel(startOffset, endOffset, text_label_3, 0, System::Windows::Forms::DataVisualization::Charting::LabelMarkStyle::None);
						this->chart1->ChartAreas[0]->AxisX->CustomLabels->Add(label_date_3);
						startOffset = startOffset + 2 * countfreq_3;
						endOffset = endOffset + 2 * countfreq_3;
					}
					this->chart1->ChartAreas[0]->AxisX->LabelStyle->Angle = -45; // Поворот надписей 
					this->chart1->ChartAreas[0]->AxisX->Interval = 2 * countfreq_3; // Масштабирование и подписей
				}
			}
			else
			{
				MessageBox::Show(this, "Заполните верным значением.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		vector_avg_3.clear(); // Очистка вектора
	}

	// Очистка скользящего среднего 3
	private: System::Void but_clear_avg_3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->chart1->Series[14]->Points->Clear(); // Очистка старого графика
	}

	///////////////////
	
	// Кнопка масштаба
	private: System::Void but_scale_Click(System::Object^ sender, System::EventArgs^ e) {

		double scale_x1, scale_x2, scale_y1, scale_y2;

		if (textBox_scale_x_1->Text != "" && textBox_scale_x_2->Text != "" && textBox_scale_y_1->Text != "" && textBox_scale_y_2->Text != "")
		{
			scale_x1 = Convert::ToDouble(textBox_scale_x_1->Text);
			scale_x2 = Convert::ToDouble(textBox_scale_x_2->Text);
			scale_y1 = Convert::ToDouble(textBox_scale_y_1->Text);
			scale_y2 = Convert::ToDouble(textBox_scale_y_2->Text);

			this->chart1->ChartAreas[0]->AxisX->Minimum = scale_x1;
			this->chart1->ChartAreas[0]->AxisX->Maximum = scale_x2;
			this->chart1->ChartAreas[0]->AxisY->Minimum = scale_y1;
			this->chart1->ChartAreas[0]->AxisY->Maximum = scale_y2;
		}
		else
		{
			MessageBox::Show(this, "Заполните все поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Ввод в поле масштаба x1
	private: System::Void textBox_scale_x_1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 44 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

	// Ввод в поле масштаба x2
	private: System::Void textBox_scale_x_2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 44 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

	// Ввод в поле масштаба y1
	private: System::Void textBox_scale_y_1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 44 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

	// Ввод в поле масштаба y2
	private: System::Void textBox_scale_y_2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 44 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

    // Ввод в поле интервала 1
	private: System::Void textBox_interval_1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

	// Ввод в поле интервала 2
	private: System::Void textBox_interval_2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}

	// Ввод в поле интервала 3
	private: System::Void textBox_interval_3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 127 || e->KeyChar == (char)Keys::Back)
		{
		}
		else
		{
			e->Handled = true;
		}
	}



//Конец кода
};
}

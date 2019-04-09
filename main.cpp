#include <iostream>
#include <vector>

using namespace std;

vector<double> input_numbers(size_t count)
{
    cerr << "Enter numbers: ";
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}
void
find_minmax(vector<double> numbers, double& min, double& max, size_t number_count)
{
    min = numbers[0];
    max = numbers[0];
    for (int i = 0; i < number_count; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        else if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

}
vector<size_t> make_histogram(double& min, double& max, int& bin_count, vector<double> numbers )
{
    const double h = (max - min) / bin_count; // Расчет ширины столбца
    vector <size_t> bins(bin_count, 0);
    for (double number : numbers)
    {
        size_t i = 0;

        while (number >= min + h * (i + 1))
        {
            i++;
        }
        if (i >= bin_count)
        {
            i = bin_count - 1;
        }
        bins[i]++;
    }
    return bins;
}

void show_histogram_text(vector <size_t> bins )
{
    size_t max_bins = bins[0];
    for (size_t bin : bins)
    {
        if (bin > max_bins)
        {
            max_bins = bin;
        }
    }
    const int MAX_WIGTH = 80 - 4;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << '0';
        }
        if (bin < 10)
        {
            cout << '0';
        }
        cout << bin << '|';
        double koef = 1;
        if (max_bins > MAX_WIGTH)
        {
            koef = (double)MAX_WIGTH / max_bins;
        }
        for (size_t i = 0; i < bin*koef; i++)
        {

            cout << '*';
        }
        cout << "\n";
    }

}

int main()
{



    size_t number_count; // Количество чисел
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count); //Сами числа
    int bin_count; // Количество корзин
    cerr << "Enter bin_count: ";
    cin >> bin_count;
    //vector <size_t> bins(bin_count, 0); //Массив, содержащий количество чисел попавших в каждую из корзин

    double min, max; //Находим наибольшее и наименьшее из чисел
    find_minmax(numbers, min, max, number_count);




    vector <size_t> bins = make_histogram(min, max, bin_count, numbers);


    show_histogram_text(bins);


    system("pause");
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int rows = 4, cols = 5;
    int seats[5][3][3][rows][cols] = {0};
    string movies[5] = {"Dhurandhar", "Pushpa 2", "KGF Chapter 2","Avengers Endgame", "Spider-Man No Way Home"};
    string theatres[3] = {"PVR Cinemas", "INOX", "Cinepolis"};
    int movieTheatre[5][3] = {{1, 1, 0},{1, 0, 1},{0, 1, 1},{1, 1, 1},{0, 1, 1}};
    string times[3] = {"10:00 AM", "2:00 PM", "7:00 PM"};

    ofstream file("bookings.txt", ios::app);
    while (true)
    {
        int movieChoice, theatreChoice, timeChoice, col;
        string name;
        char row;
        cout << "===== ONLINE MOVIE BOOKING ====="<<endl;
        cout << "Select Movie:"<<endl;
        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". " << movies[i] << endl;
        cin >> movieChoice;
        if (movieChoice < 1 || movieChoice > 5)
        {
            cout << "Invalid movie!"<<endl;
            continue;
        }
        cout << endl<<"Available Theatres:"<<endl;
        for (int i = 0; i < 3; i++)
            if (movieTheatre[movieChoice - 1][i])
                cout << i + 1 << ". " << theatres[i] << endl;
        cout << "Select Theatre: ";
        cin >> theatreChoice;
        if (!movieTheatre[movieChoice - 1][theatreChoice - 1])
        {
            cout << "This movie is not available in that theatre!"<<endl;
            continue;
        }
        cout << endl<<"Available Time Slots:"<<endl;
        for (int i = 0; i < 3; i++)
            cout << i + 1 << ". " << times[i] << endl;
        cin >> timeChoice;
        if (timeChoice < 1 || timeChoice > 3)
        {
            cout << "Invalid time!"<<endl;
            continue;
        }
        cout << endl<<"Seat Layout (0 = Available, 1 = Booked)"<<endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "Row " << char(65 + i) << " : ";
            for (int j = 0; j < cols; j++)
                cout << seats[movieChoice - 1][theatreChoice - 1][timeChoice - 1][i][j] << " ";
            cout << endl;
        }
        cout << endl<<"Enter Your Name: ";
        cin >> name;
        cout << "Enter Row (A-D): ";
        cin >> row;
        cout << "Enter Seat Number (1-5): ";
        cin >> col;
        int r = row - 'A';
        if (r < 0 || r >= rows || col < 1 || col > cols)
        {
            cout << "Invalid seat!"<<endl;
        }
        else if (seats[movieChoice - 1][theatreChoice - 1][timeChoice - 1][r][col - 1])
        {
            cout << "Seat already booked!"<<endl;
        }
        else
        {
            seats[movieChoice - 1][theatreChoice - 1][timeChoice - 1][r][col - 1] = 1;
            cout << endl<<"===== TICKET CONFIRMED ====="<<endl;
            cout << "Name: " << name << endl;
            cout << "Movie: " << movies[movieChoice - 1] << endl;
            cout << "Theatre: " << theatres[theatreChoice - 1] << endl;
            cout << "Time: " << times[timeChoice - 1] << endl;
            cout << "Seat: Row " << row << " Seat " << col << endl;
            cout << "Amount Paid: Rs.250"<<endl;
            file << "Name: " << name << " | Movie: " << movies[movieChoice - 1] << " | Theatre: " << theatres[theatreChoice - 1] << " | Time: " << times[timeChoice - 1] << " | Seat: " << row << col << " | Amount: Rs.250"<<endl;
        }
        char more;
        cout << "Book another ticket? (y/n): ";
        cin >> more;
        if (more == 'n' || more == 'N')
            break;
    }
    file.close();
    cout << endl<<"Booking data saved in bookings.txt"<<endl;
    return 0;
}
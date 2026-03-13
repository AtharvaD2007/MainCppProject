#include <iostream>
using namespace std;

int main() {
    const int rows = 4;
    const int cols = 5;
    int seats[rows][cols] = {0}; 
    int choice, row, col;

    do {
        cout << "===== ONLINE MOVIE TICKET BOOKING =====" << endl;
        cout << "1. Show Available Seats" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Seat Layout (0 = Available, 1 = Booked):" << endl;
                for(int i = 0; i < rows; i++) {
                    cout << "Row " << char(65 + i) << " : "; 
                    for(int j = 0; j < cols; j++) {
                        cout << seats[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 2:
                cout << "Enter Row (A-D): ";
                cin >> row;
                cout << "Enter Seat Number (1-5): ";
                cin >> col;

                if(row < 1 || row > rows || col < 1 || col > cols) {
                    cout << "Invalid seat selection!" << endl;
                }
                else if(seats[row-1][col-1] == 1) {
                    cout << "Seat already booked!" << endl;
                }
                else {
                    seats[row-1][col-1] = 1;

                    cout << "===== TICKET CONFIRMED =====" << endl;
                    cout << "Movie: Dhurandhar" << endl;
                    cout << "Seat: Row " << char(64 + row) 
                         << " Seat " << col << endl;
                    cout << "Status: Confirmed" << endl;
                }
                break;

            case 3:
                cout << "Thank you for using the system!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}
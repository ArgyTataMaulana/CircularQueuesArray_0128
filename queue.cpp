#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, MAX= 5;
    int queue_array[5];

    public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // 1. Cek apakah antrian sudah penuh
        if ((FRONT == 0 && REAR == MAX - 1 ) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n"; // 1.a
            return; // 1.b  
        }

        // 2. Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0; // 2.a
            REAR = 0; // 2.b
        }
    }
};
/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction 
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operattions
 * Project ini memiliki beberarpa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section CaraPenggunaan 
 * Berikut beberapa menu yang bisa digunakan:
 * 1. an queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama :Argy Tata Maulana
 * - nim  :20240140128
 * kelas  :C
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright ArgyTataMaulana@umy.ac.id (c) 2025
 */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queue
 * 
 * 
 */

class Queues {
    private:
    int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
    int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
    int MAX= 5; ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

    public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */
    void insert() {
        int num; ///< variable num untuk menyimpan nilai
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
        else{
            // jikaREAR di posisi terakhir array, kembali ke awal array
            if (REAR == MAX - 1) 
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief method untuk mengeluarkan data dalam antrian
     * data dari dalam variable queue_array
     */

    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
        cout << "Queue underflow\n";
        return;
        }
        cout << "\nThe element deleted from queue is: " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else{
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == MAX - 1)
                FRONT= 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief method untuk menampilkan data dalamantrian
     * data ditampilan yang berada variable queue_array
     */
    void display()
    {
        int FRONT_position = FRONT; ///< variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_position = REAR; ///< variable real_position untuk menandakan posisi element terakhir pada variable rear

        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // jikaFRONT_position <= REAR_positon, iterai dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else{
            // jikaFRONT_position >REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= MAX - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main() {
    Queues q; ///< objek untuk menggunakan member yang ada pada class queues
    char ch; ///< variable chuntuk meyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch(ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }

        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
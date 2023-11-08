#include "../common.h"

int main() {
    auto[infile, outfile] = openFiles();

    int tors_tid, mors_tid;
    while (infile >> tors_tid >> mors_tid) {
        int antal_morotter = 40;
        int tors_morotter = 0, mors_morotter = 0;
        int tors_counter = tors_tid, mors_counter = mors_tid; // Start counters at their respective times

        while (antal_morotter > 0) {
            if (antal_morotter == 1 && tors_counter == tors_tid && mors_counter == mors_tid) {
                break; // Neither takes the last carrot if both are ready to take it
            }

            if (tors_counter == tors_tid) { // If it's Tor's turn
                tors_morotter++;
                antal_morotter--;
                tors_counter = 1; // Reset Tor's counter
            } else {
                tors_counter++; // Increment Tor's counter
            }

            if (antal_morotter > 0 && mors_counter == mors_tid) { // If it's his mother's turn and carrots are left
                mors_morotter++;
                antal_morotter--;
                mors_counter = 1; // Reset his mother's counter
            } else if (antal_morotter > 0) {
                mors_counter++; // Increment his mother's counter
            }
        }

        outfile << tors_morotter << " " << mors_morotter << '\n';
    }

    infile.close();
    outfile.close();

    printComparison();

    return 0;
}

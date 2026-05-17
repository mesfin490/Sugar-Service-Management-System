☆ Kebele Sugar Distribution System

This is a simple C++ console project made for managing sugar distribution in a kebele public service system.

☆ About the Project

The system helps an admin:
- Login to the system
- Search a citizen using ID
- Check if the citizen exists in the record file
- Verify if sugar service is already taken or not
- Update status after service is given
- Save updated data back to file

☆ Features

- Admin login system
- Citizen search using ID
- File-based data storage (citizens.txt)
- Status checking (Taken / Not Taken)
- Automatic update of records after service
- Loop system to serve multiple citizens

☆ How It Works

1. Admin logs in using username and password
2. Enter citizen ID
3. System checks `citizens.txt`
4. If citizen is found:
   - If status is "Taken" → service rejected
   - If status is not "Taken" → payment accepted and status updated
5. Data is saved back into file
6. Admin can continue or exit

☆ File Structure

- `main.cpp` → source code
- `citizens.txt` → database file
- `records.txt` → temporary update file

☆ Sample Data Format (citizens.txt)

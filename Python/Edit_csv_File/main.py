import csv
import os
import argparse


def process_csv(csv_filepath):
    output_directory = os.getcwd()
    output_filepath = os.path.join(output_directory, 'output.csv')
    #Test
    # csv File
    with open(csv_filepath, 'r') as csv_file, open(output_filepath, 'w', newline='') as output_file:
        # Output Directory
        reader = csv.DictReader(csv_file)
        writer = csv.DictWriter(output_file, fieldnames=reader.fieldnames)
        writer.writeheader()

        # Check valid values for "Package" Row
        valid_package_values = ['0402R','0603R', 'R2010',           # Resistors
                                '0402C','0603C',                    # Capacitors
                                'F1206-M',                          # Fuses
                                'LED0603',                          # LEDs
                                'SOT-23-3 ',                        # Mosfet
                                'SOD-523', 'DO-219AB-2']            # Diodes

        # Search for Values and change them if needed
        for row in reader:
            # Change Layer
            if row['Side'] == 'BottomLayer':
                row['Side'] = 'Bottom'
            elif row['Side'] == 'TopLayer':
                row['Side'] = 'Top'

            # Change Package
            # 0402 Resistors
            if row['Package'] == 'R0402M':
                row['Package'] = '0402R'
            # 0603 Resistors
            elif row['Package'] == 'R0603M':
                row['Package'] = '0603R'


            # 0402 Capacitors
            elif row['Package'] == 'C0402':
                row['Package'] = '0402C'
            # 0603 Capacitors
            elif row['Package'] == 'C0603M':
                row['Package'] = '0603C'
            # 0402 Fuses
            elif row['Package'] == 'F0402':
                row['Package'] = '0402R'

            # Check if the Package is valid
            if row['Package'] not in valid_package_values:
                # Skip the current row if the Package value is not valid
                continue

            # Search for Value and edit if necessary
            # 0402 Capacitors
            if row['Package'] == '0402C':
                # 9pF
                if row['Value'] == '9p/50V':          
                    row['Value'] = '10pF/63V/NP0'
                # 1nF
                elif row['Value'] in ['1n/16V', '1n/50V']:
                    row['Value'] = '1nF/63V/X7R'
                # 10nF
                elif row['Value'] in ['10n/6V3', '10n/25V', '10n/50V']:
                    row['Value'] = '10nF/50V/X7R'
                # 100nF
                elif row['Value'] in ['100n/6V3', '100n/25V', '100n/50V']:
                    row['Value'] = '100nF/50V/X7R'

            # 0603 Capacitors
            elif row['Package'] == '0603C':
                # 10nF
                if row['Value'] == '10n/50V':
                    row['Value'] = '10nF/50V/X7R'
                # 10nF / 100V
                if row['Value'] == '10n/100V':
                    row['Value'] = '10nF/100V'
                # 100nF
                elif row['Value'] in ['100n/6V3', '100n/25V', '100n/50V']:
                    row['Value'] = '100nF/50V/X7R'


            # ToDo: Add NX2301P from BMS Slave
            # ToDo: 0R Resistors can also be added


            writer.writerow(row)


if __name__ == '__main__':
    try:
        parser = argparse.ArgumentParser(description='Process CSV data and save the output.')
        parser.add_argument('csv_filepath', help='Input Path to the input CSV file.')
        args = parser.parse_args()
        process_csv(args.csv_filepath)

    except Exception as e:
        # Handle the exception here or print an error message
        print(f"An error occurred: {e}")
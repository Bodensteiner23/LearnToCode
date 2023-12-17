import csv
import os

def process_csv(reader, writer):
        # Check valid values for "Package" Row
        valid_package_values = ['0402R','0603R', 'R2010',           # Resistors
                                '0402C','0603C',                    # Capacitors
                                'F1206-M',                          # Fuses
                                'LED0603',                          # LEDs
                                'SOT-23-3',                         # Mosfet
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

            writer.writerow(row)




if __name__ == '__main__':
    # Get current working directory
    directory = os.getcwd()     
    
    for filename in os.listdir(directory):      # Iterate over all files in directory
        if filename.endswith(".csv"):      
            # Read CSV filepath and create output filepath     
            csv_filepath = os.path.join(directory, filename)
            output_filepath = os.path.join(directory, f"Tool_Fraunhofer_{filename}")

            # Open Reader and Writer CSV files
            with open(csv_filepath, 'r') as csv_file, open(output_filepath, 'w', newline='') as output_file:
                # Readout CSV file
                reader = csv.DictReader(csv_file)
                
                # Check if the CSV file has the correct headers
                if reader.fieldnames is None:
                    # Skip if not
                    continue
                
                # Write new Values to CSV file
                writer = csv.DictWriter(output_file, fieldnames=reader.fieldnames)
                writer.writeheader()
                process_csv(reader, writer)
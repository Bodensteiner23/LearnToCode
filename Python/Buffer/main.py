# ============================ Imports ============================
import pandas as pd
import os
import argparse


def process_csv(csv_filepath):

    # csv Filepath
    # Readout csv Data
    df = pd.read_csv(csv_filepath)

    # output_directory
    output_directory = os.getcwd()

    # Changing Footprint Values in Package Column
    # Resistors
    df['Package'] = df['Package'].replace(to_replace='R0402M', value='0402R')
    # Capacitors
    df['Package'] = df['Package'].replace(to_replace='C0402', value='0402C')
    df['Package'] = df['Package'].replace(to_replace='C0603M', value='0603C')
    # Fuses
    df['Package'] = df['Package'].replace(to_replace='F0402', value='0402R')  # same Footprint as 0402 Resistors
    # Diodes

    # Filter Specific Values and change them to needed
    # Capacitors
    # 0402
    condition_0402_100n = (((df['Value'] == '100n/6V3') | (df['Value'] == '100n/25V') | (df['Value'] == '100n/50V'))
                           & (df['Package'] == '0402C'))
    df.loc[condition_0402_100n, 'Value'] = '100nF/50V/X7R'

    condition_0402_1n = (((df['Value'] == '1n/16V') | (df['Value'] == '1n/50V'))
                         & (df['Package'] == '0402C'))
    df.loc[condition_0402_1n, 'Value'] = '1nF/63V/X7R'

    condition_0402_10n = (((df['Value'] == '10n/6V3') | (df['Value'] == '10n/25V') | (df['Value'] == '10n/50V'))
                          & (df['Package'] == '0402C'))
    df.loc[condition_0402_10n, 'Value'] = '10nF/50V/X7R'

    condition_0402_9p = ((df['Value'] == '9p/50V')
                         & (df['Package'] == '0402C'))
    df.loc[condition_0402_9p, 'Value'] = '10pF/63V/NP0'  # ToDo: Check if 9pF -> 10pF

    # 0603
    condition_0603_100n = (((df['Value'] == '100n/6V3') | (df['Value'] == '100n/25V') | (df['Value'] == '100n/50V'))
                           & (df['Package'] == '0603C'))
    df.loc[condition_0603_100n, 'Value'] = '100nF/50V/X7R'

    condition_0603_10n = ((df['Value'] == '10n/50V')
                          & (df['Package'] == '0603C'))
    df.loc[condition_0603_10n, 'Value'] = '10nF/50V/X7R'

    # Output csv File
    output_filepath = os.path.join(output_directory, 'output.csv')
    df.to_csv(output_filepath, index=False)

    # Prove if Output Directory is valid
    os.makedirs(output_directory, exist_ok=True)


# ============================ Main ==========================
if __name__ == '__main__':
    try:
        # Parser for Console
        parser = argparse.ArgumentParser(description='Process CSV data and save the output.')

        # Adding Arguments
        parser.add_argument('csv_filepath', help='Input Path to the input CSV file.')
        # parser.add_argument('--output_directory', required=True, help='Input Path to the output directory.')
        args = parser.parse_args()
        process_csv(args.csv_filepath)
    except Exception as e:
        print(e)
    input()

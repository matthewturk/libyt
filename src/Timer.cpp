#ifdef SUPPORT_TIMER

#include "Timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

Timer::Timer(char *filename)
: m_Step(0)
{
    // Save write-to filename and path.
    strcpy(m_FileName, filename);
}

Timer::~Timer()
{
    // Clear vector.
    m_RecordTime.clear();
    m_CheckRecordTime.clear();
    m_Column.clear();
}

void Timer::print_header()
{
    // Print out header.
    FILE *output, *temp;
    output = fopen(m_FileName, "a");
    char temp_FileName[50];
    sprintf(temp_FileName, "%s_temp", m_FileName);
    temp   = fopen(temp_FileName, "r");

    for(int i = 0; i < m_Column.size(); i++){
        fprintf(output, "%s,", m_Column[i].c_str());
    }
    fprintf(output, "\n");

    // Move temperary record time to here.
    char ch;
    while( (ch = fgetc(temp)) != EOF ){
        fputc(ch, output);
    }

    // TODO: Remove temp file.

    fclose(output);
    fclose(temp);
}

void Timer::record_time(char *Column, int tag)
{
    // Get wall time.
    double time = MPI_Wtime();

    // Search column index.
    int column_index = -1;
    for(int i = 0; i < m_Column.size(); i++){
        if( strcmp(m_Column[i].c_str(), Column) == 0){
            column_index = i;
            break;
        }
    }

    // If no such column, add a new column.
    if( column_index < 0 ){
        column_index = m_Column.size();
        std::string s(Column);
        m_Column.push_back(s);
        m_RecordTime.push_back(0);
        m_CheckRecordTime.push_back(false);
    }

    // Record time, if tag = 0. Calculate time pass, if tag = 1.
    if( tag == 0 ){
        m_RecordTime[column_index] = time;
        m_CheckRecordTime[column_index] = true;
    }
    else if( tag == 1 && m_CheckRecordTime[column_index]){
        m_RecordTime[column_index] = time - m_RecordTime[column_index];
    }
}

void Timer::print_all_time()
{
    // Open temp file
    FILE *temp;
    char temp_FileName[50];
    sprintf(temp_FileName, "%s_temp", m_FileName);
    temp = fopen(temp_FileName, "a");

    // Flush all saved time.
    for(int i = 0; i < m_Column.size(); i++){
        if(m_CheckRecordTime[i]){
            fprintf(temp, "%lf,", m_RecordTime[i]);
        }
        else{
            fprintf(temp, " ,");
        }
    }
    fclose(temp);

    // Reset check m_CheckRecordTime.
    for(int i = 0; i < m_CheckRecordTime.size(); i++){
        m_CheckRecordTime[i] = false;
    }
}

#endif // #ifdef SUPPORT_TIMER

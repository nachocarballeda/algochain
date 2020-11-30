#ifndef _ERRORLOG_H_
#define _ERRORLOG_H_

#include <iostream>
#include <string>

using namespace std;

// Error msgs
#define MSG_ERROR_INVALID_FILEPATH "Invalid filepath"
#define MSG_ERROR_WRITING_TO_FILE "Couldn't write to file"
#define MSG_ERROR_INVALID_N_TX_IN "Invalid number of transaction inputs"
#define MSG_ERROR_INVALID_LINE_LENGTH "Invalid line length"
#define MSG_ERROR_INVALID_TX_ID "Invalid transaction ID"
#define MSG_ERROR_INVALID_IDX "Invalid IDx"
#define MSG_ERROR_INVALID_ADDR "Invalid address"
#define MSG_ERROR_INVALID_N_TX_OUT "Invalid number of transaction outputs"
#define MSG_ERROR_INVALID_OUTPUT_VALUE "Invalid output value"
#define MSG_ERROR_INVALID_OUTPUT_ADDR "Invalid output address"
#define MSG_ERROR_OPENING_A_FILE "Couldn't open the file"

// Warning msgs
#define MSG_WARNING_TXN_FILE_IS_EMPTY "Transaction file is empty"
#define MSG_WARNING_DIFFICULTY_INVALID "Difficulty is invalid, using default: d=0"

void showError(string, string = "");
void showWarning(string);

#endif
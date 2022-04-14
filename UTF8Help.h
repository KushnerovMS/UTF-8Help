#ifndef UTF_8_HELP_HEADER
#define UTF_8_HELP_HEADER

/**
 * @file UTF8Help.h
 * @brief It is main and only header in this library
 *
 * @warning         All functions maked as fast as I can,
 *                  so they are not secure enough. Use them cerefully.
 *
 * @example         example.cpp
 *                  
 * In example shown solution of making lower case problem (for Russian letters).
 *                  
 */

const int UNICODE_A  = 1040;
const int UNICODE_a  = 1072;
const int UNICODE_JA = 1071;
const int UNICODE_ja = 1103;
const int UNICODE_JO = 1025;
const int UNICODE_jo = 1105;


/**
 * @brief           Scan next UTF-8 symbol
 *
 * @param[in]       str     string with UTF-8 coding bytes
 *
 * @return          Count of bytes in sympol which pointer str points.
 *                  If str point at uncorrect byte, return 0.
 *                  If str point at inner byte, return count of bytes to end but as negative value.
 */
int     SymbSize    (const char* str);

/**
 * @brief UNICODE of symbol
 *
 * @param[in]       str     string with UTF-8 coding bytes
 * @param[out]      skip    (optional) write size of readed symbol as SymbSize
 *
 * @return          Return UNICODE of symbol that str points at.
 *
 * @see             SymbSize
 */
inline int UNICODE  (const char* str, int* skip = nullptr);

/**
 * @brief           Add value to symbol UNICODE
 *
 * @param[in, out]  str         string with UTF-8 coding bytes
 * @param[in]       addition    value, that will be added 
 *
 * @return          Count of bytes if symbol as SymbSize(str).
 *
 * @see             SymbSize
 *
 * @warning         Overflowing of 21 bits (max number of significal bits in UTF-8)
 *                  leads to undefined behaviour
 */
int     SymbCodeAdd (char* str, int addition);

/**
 * @brief           String to lower case
 *
 * @param           str     string that should be converted
 *
 * This function convert symbols in UTF-8 string to them lower case.
 *
 * @note            Work only with english and russian symbols
 */
void    StrToLower  (char* str);

#endif

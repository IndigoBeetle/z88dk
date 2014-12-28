/* generated by dev/build_tokens.pl */
#pragma once

/* Scan token IDs */
#define _TK_END             0    /* ""      */
#define _TK_NIL             1    /* ""      */
#define _TK_INVALID         2    /* ""      */
#define _TK_NAME            3    /* ""      */
#define _TK_LABEL           4    /* ""      */
#define _TK_NUMBER          5    /* ""      */
#define _TK_STRING          6    /* ""      */
#define _TK_TERN_COND       7    /* ""      */
#define _TK_ASMPC           8    /* "ASMPC" */
#define _TK_IF_STMT         9    /* ""      */
#define _TK_ELSE_STMT      10    /* ""      */
#define _TK_ENDIF_STMT     11    /* ""      */
#define _TK_NEWLINE        12    /* "\n"    */
#define _TK_LOG_NOT        13    /* "!"     */
#define _TK_CONST_EXPR     14    /* "#"     */
#define _TK_MOD            15    /* "%"     */
#define _TK_BIN_AND        16    /* "&"     */
#define _TK_LOG_AND        17    /* "&&"    */
#define _TK_LPAREN         18    /* "("     */
#define _TK_RPAREN         19    /* ")"     */
#define _TK_MULTIPLY       20    /* "*"     */
#define _TK_PLUS           21    /* "+"     */
#define _TK_COMMA          22    /* ","     */
#define _TK_MINUS          23    /* "-"     */
#define _TK_DOT            24    /* "."     */
#define _TK_DIVIDE         25    /* "/"     */
#define _TK_COLON          26    /* ":"     */
#define _TK_LESS           27    /* "<"     */
#define _TK_LEFT_SHIFT     28    /* "<<"    */
#define _TK_LESS_EQ        29    /* "<="    */
#define _TK_NOT_EQ         30    /* "<>"    */
#define _TK_EQUAL          31    /* "="     */
#define _TK_GREATER        32    /* ">"     */
#define _TK_RIGHT_SHIFT    33    /* ">>"    */
#define _TK_GREATER_EQ     34    /* ">="    */
#define _TK_QUESTION       35    /* "?"     */
#define _TK_LSQUARE        36    /* "["     */
#define _TK_RSQUARE        37    /* "]"     */
#define _TK_BIN_XOR        38    /* "^"     */
#define _TK_POWER          39    /* "**"    */
#define _TK_LCURLY         40    /* "{"     */
#define _TK_BIN_OR         41    /* "|"     */
#define _TK_LOG_OR         42    /* "||"    */
#define _TK_RCURLY         43    /* "}"     */
#define _TK_BIN_NOT        44    /* "~"     */
#define _TK_NZ             45    /* "NZ"    */
#define _TK_Z              46    /* "Z"     */
#define _TK_NC             47    /* "NC"    */
#define _TK_C              48    /* "C"     */
#define _TK_PO             49    /* "PO"    */
#define _TK_PE             50    /* "PE"    */
#define _TK_P              51    /* "P"     */
#define _TK_M              52    /* "M"     */
#define _TK_B              53    /* "B"     */
#define _TK_D              54    /* "D"     */
#define _TK_E              55    /* "E"     */
#define _TK_H              56    /* "H"     */
#define _TK_IXH            57    /* "IXH"   */
#define _TK_IYH            58    /* "IYH"   */
#define _TK_L              59    /* "L"     */
#define _TK_IXL            60    /* "IXL"   */
#define _TK_IYL            61    /* "IYL"   */
#define _TK_A              62    /* "A"     */
#define _TK_F              63    /* "F"     */
#define _TK_I              64    /* "I"     */
#define _TK_IIR            65    /* "IIR"   */
#define _TK_R              66    /* "R"     */
#define _TK_EIR            67    /* "EIR"   */
#define _TK_IND_C          68    /* "(C)"   */
#define _TK_BC             69    /* "BC"    */
#define _TK_DE             70    /* "DE"    */
#define _TK_HL             71    /* "HL"    */
#define _TK_IX             72    /* "IX"    */
#define _TK_IY             73    /* "IY"    */
#define _TK_AF             74    /* "AF"    */
#define _TK_SP             75    /* "SP"    */
#define _TK_AF1            76    /* "AF'"   */
#define _TK_IND_BC         77    /* "(BC)"  */
#define _TK_IND_DE         78    /* "(DE)"  */
#define _TK_IND_HL         79    /* "(HL)"  */
#define _TK_IND_IX         80    /* "(IX"   */
#define _TK_IND_IY         81    /* "(IY"   */
#define _TK_IND_SP         82    /* "(SP)"  */
#define _TK_DS_B           83    /* "DS.B"  */
#define _TK_DS_W           84    /* "DS.W"  */
#define _TK_DS_P           85    /* "DS.P"  */
#define _TK_DS_L           86    /* "DS.L"  */
#define _TK_CALL           87    /* "CALL"  */
#define _TK_CCF            88    /* "CCF"   */
#define _TK_CP             89    /* "CP"    */
#define _TK_CPD            90    /* "CPD"   */
#define _TK_CPDR           91    /* "CPDR"  */
#define _TK_CPI            92    /* "CPI"   */
#define _TK_CPIR           93    /* "CPIR"  */
#define _TK_CPL            94    /* "CPL"   */
#define _TK_DAA            95    /* "DAA"   */
#define _TK_DI             96    /* "DI"    */
#define _TK_DJNZ           97    /* "DJNZ"  */
#define _TK_EI             98    /* "EI"    */
#define _TK_EX             99    /* "EX"    */
#define _TK_EXX           100    /* "EXX"   */
#define _TK_HALT          101    /* "HALT"  */
#define _TK_IM            102    /* "IM"    */
#define _TK_IND           103    /* "IND"   */
#define _TK_INDR          104    /* "INDR"  */
#define _TK_INI           105    /* "INI"   */
#define _TK_INIR          106    /* "INIR"  */
#define _TK_JP            107    /* "JP"    */
#define _TK_JR            108    /* "JR"    */
#define _TK_LDD           109    /* "LDD"   */
#define _TK_LDDR          110    /* "LDDR"  */
#define _TK_LDI           111    /* "LDI"   */
#define _TK_LDIR          112    /* "LDIR"  */
#define _TK_NEG           113    /* "NEG"   */
#define _TK_NOP           114    /* "NOP"   */
#define _TK_OTDR          115    /* "OTDR"  */
#define _TK_OTIR          116    /* "OTIR"  */
#define _TK_OUTD          117    /* "OUTD"  */
#define _TK_OUTI          118    /* "OUTI"  */
#define _TK_POP           119    /* "POP"   */
#define _TK_PUSH          120    /* "PUSH"  */
#define _TK_RET           121    /* "RET"   */
#define _TK_RETI          122    /* "RETI"  */
#define _TK_RETN          123    /* "RETN"  */
#define _TK_RLA           124    /* "RLA"   */
#define _TK_RLCA          125    /* "RLCA"  */
#define _TK_RLD           126    /* "RLD"   */
#define _TK_RRA           127    /* "RRA"   */
#define _TK_RRCA          128    /* "RRCA"  */
#define _TK_RRD           129    /* "RRD"   */
#define _TK_RST           130    /* "RST"   */
#define _TK_SCF           131    /* "SCF"   */

#ifndef NO_TOKEN_ENUM

/* Scan token enum */
typedef enum tokid_t
{
    TK_END         = _TK_END        ,    /* =     0, ""      */
    TK_NIL         = _TK_NIL        ,    /* =     1, ""      */
    TK_INVALID     = _TK_INVALID    ,    /* =     2, ""      */
    TK_NAME        = _TK_NAME       ,    /* =     3, ""      */
    TK_LABEL       = _TK_LABEL      ,    /* =     4, ""      */
    TK_NUMBER      = _TK_NUMBER     ,    /* =     5, ""      */
    TK_STRING      = _TK_STRING     ,    /* =     6, ""      */
    TK_TERN_COND   = _TK_TERN_COND  ,    /* =     7, ""      */
    TK_ASMPC       = _TK_ASMPC      ,    /* =     8, "ASMPC" */
    TK_IF_STMT     = _TK_IF_STMT    ,    /* =     9, ""      */
    TK_ELSE_STMT   = _TK_ELSE_STMT  ,    /* =    10, ""      */
    TK_ENDIF_STMT  = _TK_ENDIF_STMT ,    /* =    11, ""      */
    TK_NEWLINE     = _TK_NEWLINE    ,    /* =    12, "\n"    */
    TK_LOG_NOT     = _TK_LOG_NOT    ,    /* =    13, "!"     */
    TK_CONST_EXPR  = _TK_CONST_EXPR ,    /* =    14, "#"     */
    TK_MOD         = _TK_MOD        ,    /* =    15, "%"     */
    TK_BIN_AND     = _TK_BIN_AND    ,    /* =    16, "&"     */
    TK_LOG_AND     = _TK_LOG_AND    ,    /* =    17, "&&"    */
    TK_LPAREN      = _TK_LPAREN     ,    /* =    18, "("     */
    TK_RPAREN      = _TK_RPAREN     ,    /* =    19, ")"     */
    TK_MULTIPLY    = _TK_MULTIPLY   ,    /* =    20, "*"     */
    TK_PLUS        = _TK_PLUS       ,    /* =    21, "+"     */
    TK_COMMA       = _TK_COMMA      ,    /* =    22, ","     */
    TK_MINUS       = _TK_MINUS      ,    /* =    23, "-"     */
    TK_DOT         = _TK_DOT        ,    /* =    24, "."     */
    TK_DIVIDE      = _TK_DIVIDE     ,    /* =    25, "/"     */
    TK_COLON       = _TK_COLON      ,    /* =    26, ":"     */
    TK_LESS        = _TK_LESS       ,    /* =    27, "<"     */
    TK_LEFT_SHIFT  = _TK_LEFT_SHIFT ,    /* =    28, "<<"    */
    TK_LESS_EQ     = _TK_LESS_EQ    ,    /* =    29, "<="    */
    TK_NOT_EQ      = _TK_NOT_EQ     ,    /* =    30, "<>"    */
    TK_EQUAL       = _TK_EQUAL      ,    /* =    31, "="     */
    TK_GREATER     = _TK_GREATER    ,    /* =    32, ">"     */
    TK_RIGHT_SHIFT = _TK_RIGHT_SHIFT,    /* =    33, ">>"    */
    TK_GREATER_EQ  = _TK_GREATER_EQ ,    /* =    34, ">="    */
    TK_QUESTION    = _TK_QUESTION   ,    /* =    35, "?"     */
    TK_LSQUARE     = _TK_LSQUARE    ,    /* =    36, "["     */
    TK_RSQUARE     = _TK_RSQUARE    ,    /* =    37, "]"     */
    TK_BIN_XOR     = _TK_BIN_XOR    ,    /* =    38, "^"     */
    TK_POWER       = _TK_POWER      ,    /* =    39, "**"    */
    TK_LCURLY      = _TK_LCURLY     ,    /* =    40, "{"     */
    TK_BIN_OR      = _TK_BIN_OR     ,    /* =    41, "|"     */
    TK_LOG_OR      = _TK_LOG_OR     ,    /* =    42, "||"    */
    TK_RCURLY      = _TK_RCURLY     ,    /* =    43, "}"     */
    TK_BIN_NOT     = _TK_BIN_NOT    ,    /* =    44, "~"     */
    TK_NZ          = _TK_NZ         ,    /* =    45, "NZ"    */
    TK_Z           = _TK_Z          ,    /* =    46, "Z"     */
    TK_NC          = _TK_NC         ,    /* =    47, "NC"    */
    TK_C           = _TK_C          ,    /* =    48, "C"     */
    TK_PO          = _TK_PO         ,    /* =    49, "PO"    */
    TK_PE          = _TK_PE         ,    /* =    50, "PE"    */
    TK_P           = _TK_P          ,    /* =    51, "P"     */
    TK_M           = _TK_M          ,    /* =    52, "M"     */
    TK_B           = _TK_B          ,    /* =    53, "B"     */
    TK_D           = _TK_D          ,    /* =    54, "D"     */
    TK_E           = _TK_E          ,    /* =    55, "E"     */
    TK_H           = _TK_H          ,    /* =    56, "H"     */
    TK_IXH         = _TK_IXH        ,    /* =    57, "IXH"   */
    TK_IYH         = _TK_IYH        ,    /* =    58, "IYH"   */
    TK_L           = _TK_L          ,    /* =    59, "L"     */
    TK_IXL         = _TK_IXL        ,    /* =    60, "IXL"   */
    TK_IYL         = _TK_IYL        ,    /* =    61, "IYL"   */
    TK_A           = _TK_A          ,    /* =    62, "A"     */
    TK_F           = _TK_F          ,    /* =    63, "F"     */
    TK_I           = _TK_I          ,    /* =    64, "I"     */
    TK_IIR         = _TK_IIR        ,    /* =    65, "IIR"   */
    TK_R           = _TK_R          ,    /* =    66, "R"     */
    TK_EIR         = _TK_EIR        ,    /* =    67, "EIR"   */
    TK_IND_C       = _TK_IND_C      ,    /* =    68, "(C)"   */
    TK_BC          = _TK_BC         ,    /* =    69, "BC"    */
    TK_DE          = _TK_DE         ,    /* =    70, "DE"    */
    TK_HL          = _TK_HL         ,    /* =    71, "HL"    */
    TK_IX          = _TK_IX         ,    /* =    72, "IX"    */
    TK_IY          = _TK_IY         ,    /* =    73, "IY"    */
    TK_AF          = _TK_AF         ,    /* =    74, "AF"    */
    TK_SP          = _TK_SP         ,    /* =    75, "SP"    */
    TK_AF1         = _TK_AF1        ,    /* =    76, "AF'"   */
    TK_IND_BC      = _TK_IND_BC     ,    /* =    77, "(BC)"  */
    TK_IND_DE      = _TK_IND_DE     ,    /* =    78, "(DE)"  */
    TK_IND_HL      = _TK_IND_HL     ,    /* =    79, "(HL)"  */
    TK_IND_IX      = _TK_IND_IX     ,    /* =    80, "(IX"   */
    TK_IND_IY      = _TK_IND_IY     ,    /* =    81, "(IY"   */
    TK_IND_SP      = _TK_IND_SP     ,    /* =    82, "(SP)"  */
    TK_DS_B        = _TK_DS_B       ,    /* =    83, "DS.B"  */
    TK_DS_W        = _TK_DS_W       ,    /* =    84, "DS.W"  */
    TK_DS_P        = _TK_DS_P       ,    /* =    85, "DS.P"  */
    TK_DS_L        = _TK_DS_L       ,    /* =    86, "DS.L"  */
    TK_CALL        = _TK_CALL       ,    /* =    87, "CALL"  */
    TK_CCF         = _TK_CCF        ,    /* =    88, "CCF"   */
    TK_CP          = _TK_CP         ,    /* =    89, "CP"    */
    TK_CPD         = _TK_CPD        ,    /* =    90, "CPD"   */
    TK_CPDR        = _TK_CPDR       ,    /* =    91, "CPDR"  */
    TK_CPI         = _TK_CPI        ,    /* =    92, "CPI"   */
    TK_CPIR        = _TK_CPIR       ,    /* =    93, "CPIR"  */
    TK_CPL         = _TK_CPL        ,    /* =    94, "CPL"   */
    TK_DAA         = _TK_DAA        ,    /* =    95, "DAA"   */
    TK_DI          = _TK_DI         ,    /* =    96, "DI"    */
    TK_DJNZ        = _TK_DJNZ       ,    /* =    97, "DJNZ"  */
    TK_EI          = _TK_EI         ,    /* =    98, "EI"    */
    TK_EX          = _TK_EX         ,    /* =    99, "EX"    */
    TK_EXX         = _TK_EXX        ,    /* =   100, "EXX"   */
    TK_HALT        = _TK_HALT       ,    /* =   101, "HALT"  */
    TK_IM          = _TK_IM         ,    /* =   102, "IM"    */
    TK_IND         = _TK_IND        ,    /* =   103, "IND"   */
    TK_INDR        = _TK_INDR       ,    /* =   104, "INDR"  */
    TK_INI         = _TK_INI        ,    /* =   105, "INI"   */
    TK_INIR        = _TK_INIR       ,    /* =   106, "INIR"  */
    TK_JP          = _TK_JP         ,    /* =   107, "JP"    */
    TK_JR          = _TK_JR         ,    /* =   108, "JR"    */
    TK_LDD         = _TK_LDD        ,    /* =   109, "LDD"   */
    TK_LDDR        = _TK_LDDR       ,    /* =   110, "LDDR"  */
    TK_LDI         = _TK_LDI        ,    /* =   111, "LDI"   */
    TK_LDIR        = _TK_LDIR       ,    /* =   112, "LDIR"  */
    TK_NEG         = _TK_NEG        ,    /* =   113, "NEG"   */
    TK_NOP         = _TK_NOP        ,    /* =   114, "NOP"   */
    TK_OTDR        = _TK_OTDR       ,    /* =   115, "OTDR"  */
    TK_OTIR        = _TK_OTIR       ,    /* =   116, "OTIR"  */
    TK_OUTD        = _TK_OUTD       ,    /* =   117, "OUTD"  */
    TK_OUTI        = _TK_OUTI       ,    /* =   118, "OUTI"  */
    TK_POP         = _TK_POP        ,    /* =   119, "POP"   */
    TK_PUSH        = _TK_PUSH       ,    /* =   120, "PUSH"  */
    TK_RET         = _TK_RET        ,    /* =   121, "RET"   */
    TK_RETI        = _TK_RETI       ,    /* =   122, "RETI"  */
    TK_RETN        = _TK_RETN       ,    /* =   123, "RETN"  */
    TK_RLA         = _TK_RLA        ,    /* =   124, "RLA"   */
    TK_RLCA        = _TK_RLCA       ,    /* =   125, "RLCA"  */
    TK_RLD         = _TK_RLD        ,    /* =   126, "RLD"   */
    TK_RRA         = _TK_RRA        ,    /* =   127, "RRA"   */
    TK_RRCA        = _TK_RRCA       ,    /* =   128, "RRCA"  */
    TK_RRD         = _TK_RRD        ,    /* =   129, "RRD"   */
    TK_RST         = _TK_RST        ,    /* =   130, "RST"   */
    TK_SCF         = _TK_SCF        ,    /* =   131, "SCF"   */
} tokid_t;

#endif

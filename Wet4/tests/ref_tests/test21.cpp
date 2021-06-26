#include "aux_macro.h"
#include "../malloc_2.cpp"
#include <iostream>

void printStats()
                    {
                        std::cout << "_num_free_blocks: " << _num_free_blocks() << std::endl;
                        std::cout << "_num_free_bytes: " << _num_free_bytes() << std::endl;
                        std::cout << "_num_allocated_blocks: " << _num_allocated_blocks() << std::endl;
                        std::cout << "_num_allocated_bytes: " << _num_allocated_bytes() << std::endl;
                        std::cout << "_num_meta_data_bytes: " << _num_meta_data_bytes() << std::endl;
                        std::cout << "_size_meta_data: " << _size_meta_data() << std::endl;
                    }
                    int main()
                    {
                        PRINT_POINTER(scalloc(29,125););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(scalloc(97,130););
printStats();
void* p1 = last_address;
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(smalloc(204););
printStats();
void* p2 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(scalloc(102,115););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p4 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(scalloc(235,6););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p5););
printStats();
PRINT_POINTER(smalloc(191););
printStats();
void* p6 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(smalloc(122););
printStats();
void* p7 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p8 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(smalloc(28););
printStats();
void* p9 = last_address;
PRINT_POINTER(srealloc(p9,148););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p10,98););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p7););
printStats();
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(smalloc(165););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(54,246););
printStats();
void* p13 = last_address;
PRINT_POINTER(smalloc(119););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(srealloc(p14,229););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(22,129););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(104););
printStats();
void* p17 = last_address;
PRINT_POINTER(scalloc(223,21););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p18,230););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(scalloc(46,23););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(smalloc(166););
printStats();
void* p21 = last_address;
PRINT_POINTER(srealloc(p21,97););
printStats();
void* p22 = last_address;
PRINT_POINTER(scalloc(239,45););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p23,93););
printStats();
void* p24 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(scalloc(106,167););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p22,7););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p26,130););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(209,202););
printStats();
void* p28 = last_address;
PRINT_POINTER(scalloc(184,145););
printStats();
void* p29 = last_address;
DEBUG_PRINT(sfree(p25););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(srealloc(p13,92););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(175,55););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(59););
printStats();
void* p32 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(srealloc(p29,116););
printStats();
void* p33 = last_address;
PRINT_POINTER(srealloc(p28,146););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
PRINT_POINTER(smalloc(108););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p34,66););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p16,238););
printStats();
void* p37 = last_address;
PRINT_POINTER(srealloc(p31,54););
printStats();
void* p38 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
DEBUG_PRINT(sfree(p30););
printStats();
DEBUG_PRINT(sfree(p38););
printStats();
PRINT_POINTER(scalloc(74,18););
printStats();
void* p39 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(scalloc(184,180););
printStats();
void* p40 = last_address;
PRINT_POINTER(srealloc(p35,39););
printStats();
void* p41 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(smalloc(94););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(scalloc(114,228););
printStats();
void* p43 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(srealloc(p41,186););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p44,4););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(srealloc(p42,119););
printStats();
void* p46 = last_address;
PRINT_POINTER(srealloc(p46,72););
printStats();
void* p47 = last_address;
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(scalloc(28,209););
printStats();
void* p48 = last_address;
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(srealloc(p40,247););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(33,209););
printStats();
void* p50 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p51 = last_address;
PRINT_POINTER(srealloc(p50,19););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p51););
printStats();
PRINT_POINTER(srealloc(p52,12););
printStats();
void* p53 = last_address;
PRINT_POINTER(smalloc(120););
printStats();
void* p54 = last_address;
PRINT_POINTER(srealloc(p54,171););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(140,122););
printStats();
void* p56 = last_address;
PRINT_POINTER(srealloc(p53,22););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(86););
printStats();
void* p58 = last_address;
PRINT_POINTER(smalloc(85););
printStats();
void* p59 = last_address;
PRINT_POINTER(smalloc(222););
printStats();
void* p60 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(srealloc(p59,76););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p56,193););
printStats();
void* p62 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
DEBUG_PRINT(sfree(p58););
printStats();
PRINT_POINTER(srealloc(p60,162););
printStats();
void* p63 = last_address;
PRINT_POINTER(smalloc(208););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(34););
printStats();
void* p66 = last_address;
PRINT_POINTER(smalloc(46););
printStats();
void* p67 = last_address;
PRINT_POINTER(scalloc(124,213););
printStats();
void* p68 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(smalloc(125););
printStats();
void* p69 = last_address;
PRINT_POINTER(srealloc(p62,0););
printStats();
void* p70 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p71 = last_address;
PRINT_POINTER(srealloc(p71,73););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p69););
printStats();
PRINT_POINTER(srealloc(p57,180););
printStats();
void* p73 = last_address;
PRINT_POINTER(scalloc(143,22););
printStats();
void* p74 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(scalloc(216,128););
printStats();
void* p75 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
DEBUG_PRINT(sfree(p75););
printStats();
PRINT_POINTER(scalloc(64,112););
printStats();
void* p76 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
PRINT_POINTER(srealloc(p67,115););
printStats();
void* p77 = last_address;
PRINT_POINTER(srealloc(p64,147););
printStats();
void* p78 = last_address;
PRINT_POINTER(srealloc(p61,43););
printStats();
void* p79 = last_address;
PRINT_POINTER(srealloc(p68,213););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p63,90););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p79););
printStats();
PRINT_POINTER(scalloc(11,209););
printStats();
void* p82 = last_address;
PRINT_POINTER(scalloc(59,247););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p80,11););
printStats();
void* p84 = last_address;
PRINT_POINTER(scalloc(184,170););
printStats();
void* p85 = last_address;
PRINT_POINTER(srealloc(p73,96););
printStats();
void* p86 = last_address;
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(scalloc(64,220););
printStats();
void* p87 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(smalloc(87););
printStats();
void* p88 = last_address;
PRINT_POINTER(scalloc(172,243););
printStats();
void* p89 = last_address;
PRINT_POINTER(srealloc(p88,94););
printStats();
void* p90 = last_address;
PRINT_POINTER(srealloc(p84,11););
printStats();
void* p91 = last_address;
PRINT_POINTER(srealloc(p90,101););
printStats();
void* p92 = last_address;
PRINT_POINTER(smalloc(30););
printStats();
void* p93 = last_address;
PRINT_POINTER(scalloc(118,207););
printStats();
void* p94 = last_address;
PRINT_POINTER(smalloc(87););
printStats();
void* p95 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(133,126););
printStats();
void* p97 = last_address;
DEBUG_PRINT(sfree(p97););
printStats();
PRINT_POINTER(scalloc(176,25););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(srealloc(p94,122););
printStats();
void* p99 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(smalloc(234););
printStats();
void* p100 = last_address;
PRINT_POINTER(srealloc(p93,173););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p102 = last_address;
PRINT_POINTER(smalloc(45););
printStats();
void* p103 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
DEBUG_PRINT(sfree(p103););
printStats();
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(srealloc(p86,246););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(240,39););
printStats();
void* p105 = last_address;
PRINT_POINTER(scalloc(202,229););
printStats();
void* p106 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(scalloc(21,187););
printStats();
void* p107 = last_address;
PRINT_POINTER(smalloc(144););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p82,220););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(222,122););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p100,180););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(scalloc(225,12););
printStats();
void* p112 = last_address;
PRINT_POINTER(scalloc(188,80););
printStats();
void* p113 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(scalloc(210,12););
printStats();
void* p114 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(srealloc(p83,193););
printStats();
void* p115 = last_address;
DEBUG_PRINT(sfree(p111););
printStats();
PRINT_POINTER(srealloc(p107,67););
printStats();
void* p116 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p117 = last_address;
PRINT_POINTER(scalloc(202,17););
printStats();
void* p118 = last_address;
PRINT_POINTER(scalloc(40,42););
printStats();
void* p119 = last_address;
PRINT_POINTER(srealloc(p108,179););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p121 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(smalloc(31););
printStats();
void* p123 = last_address;
PRINT_POINTER(smalloc(133););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p119););
printStats();
PRINT_POINTER(scalloc(47,123););
printStats();
void* p125 = last_address;
DEBUG_PRINT(sfree(p120););
printStats();
PRINT_POINTER(srealloc(p124,200););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(smalloc(70););
printStats();
void* p127 = last_address;
PRINT_POINTER(scalloc(174,168););
printStats();
void* p128 = last_address;
PRINT_POINTER(srealloc(p128,186););
printStats();
void* p129 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(83,198););
printStats();
void* p131 = last_address;
PRINT_POINTER(srealloc(p113,55););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
PRINT_POINTER(srealloc(p122,92););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p105,166););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p125););
printStats();
PRINT_POINTER(srealloc(p116,99););
printStats();
void* p135 = last_address;
PRINT_POINTER(scalloc(184,162););
printStats();
void* p136 = last_address;
PRINT_POINTER(srealloc(p136,99););
printStats();
void* p137 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(smalloc(187););
printStats();
void* p138 = last_address;
PRINT_POINTER(srealloc(p91,107););
printStats();
void* p139 = last_address;
PRINT_POINTER(scalloc(18,86););
printStats();
void* p140 = last_address;
PRINT_POINTER(smalloc(99););
printStats();
void* p141 = last_address;
PRINT_POINTER(srealloc(p127,135););
printStats();
void* p142 = last_address;
DEBUG_PRINT(sfree(p131););
printStats();
PRINT_POINTER(scalloc(91,212););
printStats();
void* p143 = last_address;
PRINT_POINTER(srealloc(p78,208););
printStats();
void* p144 = last_address;
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(smalloc(147););
printStats();
void* p145 = last_address;
PRINT_POINTER(scalloc(149,240););
printStats();
void* p146 = last_address;
PRINT_POINTER(srealloc(p135,203););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(137,202););
printStats();
void* p148 = last_address;
PRINT_POINTER(srealloc(p137,1););
printStats();
void* p149 = last_address;
PRINT_POINTER(scalloc(234,63););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(79););
printStats();
void* p151 = last_address;
PRINT_POINTER(srealloc(p118,208););
printStats();
void* p152 = last_address;
DEBUG_PRINT(sfree(p148););
printStats();
PRINT_POINTER(srealloc(p114,94););
printStats();
void* p153 = last_address;
PRINT_POINTER(scalloc(32,222););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p141););
printStats();
PRINT_POINTER(scalloc(175,104););
printStats();
void* p155 = last_address;
PRINT_POINTER(srealloc(p104,222););
printStats();
void* p156 = last_address;
PRINT_POINTER(smalloc(151););
printStats();
void* p157 = last_address;
PRINT_POINTER(srealloc(p144,98););
printStats();
void* p158 = last_address;
DEBUG_PRINT(sfree(p150););
printStats();
PRINT_POINTER(smalloc(3););
printStats();
void* p159 = last_address;
PRINT_POINTER(scalloc(220,227););
printStats();
void* p160 = last_address;
PRINT_POINTER(scalloc(206,128););
printStats();
void* p161 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p162 = last_address;
PRINT_POINTER(scalloc(170,123););
printStats();
void* p163 = last_address;
DEBUG_PRINT(sfree(p157););
printStats();
PRINT_POINTER(scalloc(55,171););
printStats();
void* p164 = last_address;
PRINT_POINTER(scalloc(177,58););
printStats();
void* p165 = last_address;
PRINT_POINTER(scalloc(219,147););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p161););
printStats();
PRINT_POINTER(scalloc(19,178););
printStats();
void* p167 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(237,30););
printStats();
void* p169 = last_address;
PRINT_POINTER(srealloc(p123,27););
printStats();
void* p170 = last_address;
PRINT_POINTER(scalloc(54,159););
printStats();
void* p171 = last_address;
PRINT_POINTER(smalloc(15););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(218););
printStats();
void* p173 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p174 = last_address;
PRINT_POINTER(srealloc(p172,74););
printStats();
void* p175 = last_address;
PRINT_POINTER(smalloc(83););
printStats();
void* p176 = last_address;
DEBUG_PRINT(sfree(p174););
printStats();
PRINT_POINTER(smalloc(125););
printStats();
void* p177 = last_address;
PRINT_POINTER(srealloc(p126,169););
printStats();
void* p178 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
DEBUG_PRINT(sfree(p166););
printStats();
DEBUG_PRINT(sfree(p177););
printStats();
PRINT_POINTER(smalloc(208););
printStats();
void* p179 = last_address;
PRINT_POINTER(srealloc(p146,99););
printStats();
void* p180 = last_address;
PRINT_POINTER(srealloc(p139,183););
printStats();
void* p181 = last_address;
PRINT_POINTER(scalloc(205,174););
printStats();
void* p182 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(111););
printStats();
void* p184 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p185 = last_address;
PRINT_POINTER(scalloc(194,118););
printStats();
void* p186 = last_address;
DEBUG_PRINT(sfree(p173););
printStats();
PRINT_POINTER(srealloc(p169,155););
printStats();
void* p187 = last_address;
DEBUG_PRINT(sfree(p187););
printStats();
PRINT_POINTER(scalloc(137,40););
printStats();
void* p188 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(scalloc(61,173););
printStats();
void* p189 = last_address;
PRINT_POINTER(scalloc(31,54););
printStats();
void* p190 = last_address;
PRINT_POINTER(srealloc(p167,246););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p155,27););
printStats();
void* p192 = last_address;
PRINT_POINTER(srealloc(p151,126););
printStats();
void* p193 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p194 = last_address;
DEBUG_PRINT(sfree(p184););
printStats();
PRINT_POINTER(scalloc(242,82););
printStats();
void* p195 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p196 = last_address;
PRINT_POINTER(scalloc(5,186););
printStats();
void* p197 = last_address;
PRINT_POINTER(srealloc(p180,205););
printStats();
void* p198 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p199 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p200 = last_address;
DEBUG_PRINT(sfree(p197););
printStats();
PRINT_POINTER(scalloc(34,240););
printStats();
void* p201 = last_address;
PRINT_POINTER(smalloc(225););
printStats();
void* p202 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p203 = last_address;
PRINT_POINTER(smalloc(79););
printStats();
void* p204 = last_address;
PRINT_POINTER(scalloc(40,73););
printStats();
void* p205 = last_address;
PRINT_POINTER(scalloc(217,51););
printStats();
void* p206 = last_address;
PRINT_POINTER(srealloc(p159,74););
printStats();
void* p207 = last_address;
PRINT_POINTER(scalloc(232,23););
printStats();
void* p208 = last_address;
PRINT_POINTER(scalloc(245,25););
printStats();
void* p209 = last_address;
PRINT_POINTER(scalloc(1,232););
printStats();
void* p210 = last_address;
PRINT_POINTER(smalloc(103););
printStats();
void* p211 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p212 = last_address;
PRINT_POINTER(smalloc(105););
printStats();
void* p213 = last_address;
PRINT_POINTER(srealloc(p202,22););
printStats();
void* p214 = last_address;
DEBUG_PRINT(sfree(p196););
printStats();
PRINT_POINTER(srealloc(p203,210););
printStats();
void* p215 = last_address;
DEBUG_PRINT(sfree(p133););
printStats();
DEBUG_PRINT(sfree(p207););
printStats();
PRINT_POINTER(scalloc(40,204););
printStats();
void* p216 = last_address;
PRINT_POINTER(srealloc(p178,232););
printStats();
void* p217 = last_address;
DEBUG_PRINT(sfree(p134););
printStats();
DEBUG_PRINT(sfree(p208););
printStats();
PRINT_POINTER(smalloc(39););
printStats();
void* p218 = last_address;
DEBUG_PRINT(sfree(p188););
printStats();
DEBUG_PRINT(sfree(p152););
printStats();
PRINT_POINTER(scalloc(200,48););
printStats();
void* p219 = last_address;
PRINT_POINTER(scalloc(11,217););
printStats();
void* p220 = last_address;
DEBUG_PRINT(sfree(p121););
printStats();
PRINT_POINTER(smalloc(203););
printStats();
void* p221 = last_address;
PRINT_POINTER(srealloc(p205,123););
printStats();
void* p222 = last_address;
PRINT_POINTER(smalloc(38););
printStats();
void* p223 = last_address;
PRINT_POINTER(smalloc(13););
printStats();
void* p224 = last_address;
PRINT_POINTER(smalloc(4););
printStats();
void* p225 = last_address;
DEBUG_PRINT(sfree(p138););
printStats();
PRINT_POINTER(srealloc(p221,48););
printStats();
void* p226 = last_address;
PRINT_POINTER(scalloc(246,111););
printStats();
void* p227 = last_address;
PRINT_POINTER(srealloc(p212,233););
printStats();
void* p228 = last_address;
PRINT_POINTER(smalloc(40););
printStats();
void* p229 = last_address;
PRINT_POINTER(srealloc(p194,129););
printStats();
void* p230 = last_address;
PRINT_POINTER(smalloc(230););
printStats();
void* p231 = last_address;
PRINT_POINTER(srealloc(p219,146););
printStats();
void* p232 = last_address;
PRINT_POINTER(scalloc(191,124););
printStats();
void* p233 = last_address;
PRINT_POINTER(srealloc(p165,6););
printStats();
void* p234 = last_address;
PRINT_POINTER(srealloc(p227,171););
printStats();
void* p235 = last_address;
DEBUG_PRINT(sfree(p140););
printStats();
PRINT_POINTER(srealloc(p198,14););
printStats();
void* p236 = last_address;
PRINT_POINTER(smalloc(193););
printStats();
void* p237 = last_address;
DEBUG_PRINT(sfree(p81););
printStats();
PRINT_POINTER(smalloc(14););
printStats();
void* p238 = last_address;
PRINT_POINTER(scalloc(14,71););
printStats();
void* p239 = last_address;
PRINT_POINTER(smalloc(196););
printStats();
void* p240 = last_address;
PRINT_POINTER(scalloc(23,230););
printStats();
void* p241 = last_address;
PRINT_POINTER(srealloc(p115,55););
printStats();
void* p242 = last_address;
PRINT_POINTER(scalloc(106,108););
printStats();
void* p243 = last_address;
PRINT_POINTER(scalloc(86,12););
printStats();
void* p244 = last_address;
PRINT_POINTER(scalloc(224,59););
printStats();
void* p245 = last_address;
PRINT_POINTER(scalloc(139,12););
printStats();
void* p246 = last_address;
DEBUG_PRINT(sfree(p234););
printStats();
PRINT_POINTER(scalloc(150,149););
printStats();
void* p247 = last_address;
PRINT_POINTER(scalloc(186,65););
printStats();
void* p248 = last_address;
DEBUG_PRINT(sfree(p201););
printStats();
DEBUG_PRINT(sfree(p158););
printStats();
PRINT_POINTER(scalloc(119,79););
printStats();
void* p249 = last_address;
DEBUG_PRINT(sfree(p237););
printStats();
DEBUG_PRINT(sfree(p228););
printStats();
PRINT_POINTER(scalloc(166,171););
printStats();
void* p250 = last_address;
PRINT_POINTER(srealloc(p163,31););
printStats();
void* p251 = last_address;
PRINT_POINTER(srealloc(p233,180););
printStats();
void* p252 = last_address;
PRINT_POINTER(srealloc(p149,212););
printStats();
void* p253 = last_address;
PRINT_POINTER(srealloc(p244,1););
printStats();
void* p254 = last_address;
PRINT_POINTER(scalloc(88,95););
printStats();
void* p255 = last_address;
DEBUG_PRINT(sfree(p210););
printStats();
PRINT_POINTER(scalloc(206,189););
printStats();
void* p256 = last_address;
PRINT_POINTER(scalloc(0,166););
printStats();
void* p257 = last_address;
PRINT_POINTER(scalloc(37,216););
printStats();
void* p258 = last_address;
PRINT_POINTER(srealloc(p192,17););
printStats();
void* p259 = last_address;
PRINT_POINTER(scalloc(156,60););
printStats();
void* p260 = last_address;
PRINT_POINTER(scalloc(41,50););
printStats();
void* p261 = last_address;
PRINT_POINTER(smalloc(118););
printStats();
void* p262 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p263 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p264 = last_address;
DEBUG_PRINT(sfree(p231););
printStats();
PRINT_POINTER(smalloc(72););
printStats();
void* p265 = last_address;
PRINT_POINTER(scalloc(11,240););
printStats();
void* p266 = last_address;
PRINT_POINTER(srealloc(p263,109););
printStats();
void* p267 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p268 = last_address;
DEBUG_PRINT(sfree(p204););
printStats();
PRINT_POINTER(srealloc(p223,213););
printStats();
void* p269 = last_address;
PRINT_POINTER(scalloc(226,246););
printStats();
void* p270 = last_address;
PRINT_POINTER(scalloc(8,136););
printStats();
void* p271 = last_address;
PRINT_POINTER(smalloc(157););
printStats();
void* p272 = last_address;
PRINT_POINTER(srealloc(p185,37););
printStats();
void* p273 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p274 = last_address;
PRINT_POINTER(scalloc(197,200););
printStats();
void* p275 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p276 = last_address;
PRINT_POINTER(scalloc(156,246););
printStats();
void* p277 = last_address;
DEBUG_PRINT(sfree(p261););
printStats();
DEBUG_PRINT(sfree(p266););
printStats();
PRINT_POINTER(smalloc(217););
printStats();
void* p278 = last_address;
PRINT_POINTER(scalloc(187,119););
printStats();
void* p279 = last_address;
DEBUG_PRINT(sfree(p239););
printStats();
PRINT_POINTER(srealloc(p243,142););
printStats();
void* p280 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(scalloc(195,20););
printStats();
void* p281 = last_address;
DEBUG_PRINT(sfree(p249););
printStats();
PRINT_POINTER(srealloc(p260,202););
printStats();
void* p282 = last_address;
PRINT_POINTER(scalloc(141,237););
printStats();
void* p283 = last_address;
PRINT_POINTER(scalloc(171,198););
printStats();
void* p284 = last_address;
DEBUG_PRINT(sfree(p186););
printStats();
DEBUG_PRINT(sfree(p273););
printStats();
PRINT_POINTER(srealloc(p154,53););
printStats();
void* p285 = last_address;
PRINT_POINTER(scalloc(229,169););
printStats();
void* p286 = last_address;
PRINT_POINTER(srealloc(p276,36););
printStats();
void* p287 = last_address;
PRINT_POINTER(scalloc(142,122););
printStats();
void* p288 = last_address;
DEBUG_PRINT(sfree(p281););
printStats();
PRINT_POINTER(smalloc(191););
printStats();
void* p289 = last_address;
PRINT_POINTER(srealloc(p257,72););
printStats();
void* p290 = last_address;
PRINT_POINTER(srealloc(p209,39););
printStats();
void* p291 = last_address;
PRINT_POINTER(smalloc(241););
printStats();
void* p292 = last_address;
PRINT_POINTER(srealloc(p242,230););
printStats();
void* p293 = last_address;
DEBUG_PRINT(sfree(p147););
printStats();
PRINT_POINTER(srealloc(p284,82););
printStats();
void* p294 = last_address;
DEBUG_PRINT(sfree(p269););
printStats();
DEBUG_PRINT(sfree(p259););
printStats();
DEBUG_PRINT(sfree(p98););
printStats();
DEBUG_PRINT(sfree(p222););
printStats();
PRINT_POINTER(smalloc(195););
printStats();
void* p295 = last_address;
PRINT_POINTER(srealloc(p200,59););
printStats();
void* p296 = last_address;
DEBUG_PRINT(sfree(p277););
printStats();
PRINT_POINTER(smalloc(109););
printStats();
void* p297 = last_address;
DEBUG_PRINT(sfree(p156););
printStats();
PRINT_POINTER(smalloc(240););
printStats();
void* p298 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p299 = last_address;
PRINT_POINTER(scalloc(9,62););
printStats();
void* p300 = last_address;
DEBUG_PRINT(sfree(p220););
printStats();
DEBUG_PRINT(sfree(p280););
printStats();
DEBUG_PRINT(sfree(p236););
printStats();
PRINT_POINTER(srealloc(p191,177););
printStats();
void* p301 = last_address;
PRINT_POINTER(smalloc(235););
printStats();
void* p302 = last_address;
PRINT_POINTER(scalloc(236,180););
printStats();
void* p303 = last_address;
DEBUG_PRINT(sfree(p294););
printStats();
PRINT_POINTER(scalloc(135,153););
printStats();
void* p304 = last_address;
DEBUG_PRINT(sfree(p275););
printStats();
PRINT_POINTER(srealloc(p282,222););
printStats();
void* p305 = last_address;
PRINT_POINTER(scalloc(36,153););
printStats();
void* p306 = last_address;
PRINT_POINTER(srealloc(p225,136););
printStats();
void* p307 = last_address;
PRINT_POINTER(smalloc(134););
printStats();
void* p308 = last_address;
PRINT_POINTER(srealloc(p256,34););
printStats();
void* p309 = last_address;
PRINT_POINTER(scalloc(162,114););
printStats();
void* p310 = last_address;
DEBUG_PRINT(sfree(p164););
printStats();
PRINT_POINTER(srealloc(p310,33););
printStats();
void* p311 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(smalloc(243););
printStats();
void* p312 = last_address;
PRINT_POINTER(scalloc(85,19););
printStats();
void* p313 = last_address;
DEBUG_PRINT(sfree(p313););
printStats();
DEBUG_PRINT(sfree(p215););
printStats();
PRINT_POINTER(srealloc(p189,155););
printStats();
void* p314 = last_address;
DEBUG_PRINT(sfree(p218););
printStats();
PRINT_POINTER(srealloc(p299,222););
printStats();
void* p315 = last_address;
DEBUG_PRINT(sfree(p182););
printStats();
DEBUG_PRINT(sfree(p245););
printStats();
PRINT_POINTER(srealloc(p238,145););
printStats();
void* p316 = last_address;
PRINT_POINTER(scalloc(58,240););
printStats();
void* p317 = last_address;
PRINT_POINTER(srealloc(p265,13););
printStats();
void* p318 = last_address;
PRINT_POINTER(srealloc(p268,243););
printStats();
void* p319 = last_address;
DEBUG_PRINT(sfree(p241););
printStats();
PRINT_POINTER(smalloc(65););
printStats();
void* p320 = last_address;
PRINT_POINTER(scalloc(72,183););
printStats();
void* p321 = last_address;
PRINT_POINTER(smalloc(178););
printStats();
void* p322 = last_address;
PRINT_POINTER(scalloc(13,238););
printStats();
void* p323 = last_address;
DEBUG_PRINT(sfree(p303););
printStats();
PRINT_POINTER(smalloc(75););
printStats();
void* p324 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p325 = last_address;
PRINT_POINTER(smalloc(242););
printStats();
void* p326 = last_address;
DEBUG_PRINT(sfree(p295););
printStats();
PRINT_POINTER(scalloc(151,192););
printStats();
void* p327 = last_address;
DEBUG_PRINT(sfree(p314););
printStats();
DEBUG_PRINT(sfree(p253););
printStats();
PRINT_POINTER(scalloc(58,198););
printStats();
void* p328 = last_address;
PRINT_POINTER(srealloc(p291,16););
printStats();
void* p329 = last_address;
DEBUG_PRINT(sfree(p270););
printStats();
PRINT_POINTER(srealloc(p274,145););
printStats();
void* p330 = last_address;
PRINT_POINTER(scalloc(148,172););
printStats();
void* p331 = last_address;
PRINT_POINTER(scalloc(79,157););
printStats();
void* p332 = last_address;
PRINT_POINTER(scalloc(112,202););
printStats();
void* p333 = last_address;
PRINT_POINTER(scalloc(73,61););
printStats();
void* p334 = last_address;
PRINT_POINTER(srealloc(p288,0););
printStats();
void* p335 = last_address;
PRINT_POINTER(smalloc(240););
printStats();
void* p336 = last_address;
PRINT_POINTER(srealloc(p278,92););
printStats();
void* p337 = last_address;
PRINT_POINTER(scalloc(221,196););
printStats();
void* p338 = last_address;
PRINT_POINTER(scalloc(32,65););
printStats();
void* p339 = last_address;
PRINT_POINTER(scalloc(55,179););
printStats();
void* p340 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p341 = last_address;
PRINT_POINTER(srealloc(p229,136););
printStats();
void* p342 = last_address;
PRINT_POINTER(srealloc(p252,248););
printStats();
void* p343 = last_address;
PRINT_POINTER(smalloc(72););
printStats();
void* p344 = last_address;
PRINT_POINTER(smalloc(126););
printStats();
void* p345 = last_address;
PRINT_POINTER(scalloc(10,38););
printStats();
void* p346 = last_address;
DEBUG_PRINT(sfree(p345););
printStats();
PRINT_POINTER(smalloc(16););
printStats();
void* p347 = last_address;
PRINT_POINTER(srealloc(p342,240););
printStats();
void* p348 = last_address;
DEBUG_PRINT(sfree(p171););
printStats();
PRINT_POINTER(smalloc(33););
printStats();
void* p349 = last_address;
PRINT_POINTER(srealloc(p329,67););
printStats();
void* p350 = last_address;
PRINT_POINTER(smalloc(13););
printStats();
void* p351 = last_address;
PRINT_POINTER(scalloc(64,183););
printStats();
void* p352 = last_address;
PRINT_POINTER(srealloc(p287,159););
printStats();
void* p353 = last_address;
DEBUG_PRINT(sfree(p160););
printStats();
PRINT_POINTER(smalloc(156););
printStats();
void* p354 = last_address;
PRINT_POINTER(smalloc(215););
printStats();
void* p355 = last_address;
PRINT_POINTER(scalloc(89,215););
printStats();
void* p356 = last_address;
PRINT_POINTER(smalloc(211););
printStats();
void* p357 = last_address;
PRINT_POINTER(srealloc(p285,36););
printStats();
void* p358 = last_address;
PRINT_POINTER(smalloc(61););
printStats();
void* p359 = last_address;
PRINT_POINTER(srealloc(p333,66););
printStats();
void* p360 = last_address;
DEBUG_PRINT(sfree(p309););
printStats();
PRINT_POINTER(smalloc(103););
printStats();
void* p361 = last_address;
DEBUG_PRINT(sfree(p308););
printStats();
PRINT_POINTER(srealloc(p352,58););
printStats();
void* p362 = last_address;
DEBUG_PRINT(sfree(p232););
printStats();
PRINT_POINTER(srealloc(p296,172););
printStats();
void* p363 = last_address;
}

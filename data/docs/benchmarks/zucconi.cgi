#!/usr/local/www/cgi-bin/tablecg
#
# $DragonFly: site/data/docs/benchmarks/Attic/zucconi.cgi,v 1.1 2004/01/26 20:34:42 justin Exp $

$TITLE(DragonFly Benchmarks - Zucconi, January 2004)

<P>
<I>Committer's note: Jean-Marc Zucconi benchmarked various flavors of FreeBSD and DragonFly on
a multiprocessor x86 system in Jaunary of 2004.  He has kindly allowed us to
print the results here.  Quoted text is his.</I>
<P>

<TABLE BORDER="0">
<TR><TH>                                          </TH><TH>FreeBSD-4.9</TH><TH>    FreeBSD-5.1</TH><TH>     FreeBSD-5.2</TH><TH>       DragonFly</TH></TR>
<TR BGCOLOR="#EEEEEE"><TD>Dhrystone 2 without register variables </TD><TD>660050.1 lps  </TD><TD> 650148.4 lps   </TD><TD> 661362.9 lps  </TD><TD> 667712.8 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Dhrystone 2 using register variables   </TD><TD>660062.3 lps  </TD><TD> 650258.6 lps   </TD><TD> 661430.8 lps  </TD><TD> 665312.0 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Arithmetic Test (type = arithoh)       </TD><TD>518178.8 lps  </TD><TD>1527450.3 lps   </TD><TD>1055234.6 lps  </TD><TD>1513511.1 lps</TD></TR>
<TR><TD>Arithmetic Test (type = register)      </TD><TD> 89009.9 lps  </TD><TD>  91551.8 lps   </TD><TD>  91672.9 lps  </TD><TD>  87657.5 lps</TD></TR>
<TR><TD>Arithmetic Test (type = short)         </TD><TD> 81709.0 lps  </TD><TD>  91413.9 lps   </TD><TD>  88086.6 lps  </TD><TD>  81487.4 lps</TD></TR>
<TR><TD>Arithmetic Test (type = int)           </TD><TD> 89030.8 lps  </TD><TD>  91550.6 lps   </TD><TD>  91662.9 lps  </TD><TD>  88331.6 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Arithmetic Test (type = long)          </TD><TD> 88999.0 lps  </TD><TD>  91544.6 lps   </TD><TD>  91682.2 lps  </TD><TD>  89063.4 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Arithmetic Test (type = float)         </TD><TD> 88148.0 lps  </TD><TD> 105020.8 lps   </TD><TD> 105154.2 lps  </TD><TD>  87531.7 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Arithmetic Test (type = double)        </TD><TD> 88148.2 lps  </TD><TD> 104999.4 lps   </TD><TD> 105242.2 lps  </TD><TD>  87891.6 lps</TD></TR>
<TR><TD>System Call Overhead Test              </TD><TD>107461.9 lps  </TD><TD>  82630.7 lps   </TD><TD>  82300.9 lps  </TD><TD>  89537.9 lps</TD></TR>
<TR><TD>Pipe Throughput Test                   </TD><TD>133588.2 lps  </TD><TD>  86297.9 lps   </TD><TD>  78012.8 lps  </TD><TD> 106999.4 lps</TD></TR>
<TR><TD>Pipe-based Context Switching Test      </TD><TD> 38436.5 lps  </TD><TD>  23821.9 lps   </TD><TD>  23268.0 lps  </TD><TD>  18203.4 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Process Creation Test                  </TD><TD>  2736.3 lps  </TD><TD>   1574.6 lps   </TD><TD>   1517.7 lps  </TD><TD>   1569.6 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Execl Throughput Test                  </TD><TD>  1772.9 lps  </TD><TD>   1521.2 lps   </TD><TD>   1371.7 lps  </TD><TD>   1497.6 lps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>File Read  (10 seconds)                </TD><TD>179477.0 KBps </TD><TD> 167848.0 KBps  </TD><TD>  181930.0 KBps </TD><TD> 179972.0 KBps</TD></TR>
<TR><TD>File Write (10 seconds)                </TD><TD> 18633.0 KBps </TD><TD>  12800.0 KBps  </TD><TD>   7800.0 KBps </TD><TD>12033.0 KBps</TD></TR>
<TR><TD>File Copy  (10 seconds)                </TD><TD> 16298.0 KBps </TD><TD>  11944.0 KBps  </TD><TD>   4436.0 KBps </TD><TD>  11905.0 KBps</TD></TR>
<TR><TD>File Read  (30 seconds)                </TD><TD>179598.0 KBps </TD><TD> 169150.0 KBps  </TD><TD>  39068.0 KBps </TD><TD> 182251.0 KBps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>File Write (30 seconds)               </TD><TD>    18399.0 KBps   </TD><TD>12589.0 KBps     </TD><TD>11933.0 KBps    </TD><TD>18277.0 KBps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>File Copy  (30 seconds)               </TD><TD>    15297.0 KBps  </TD><TD> 11468.0 KBps     </TD><TD>11811.0 KBps    </TD><TD>15308.0 KBps</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>C Compiler Test                        </TD><TD>   428.1 lpm  </TD><TD>    258.4 lpm   </TD><TD>    241.2 lpm  </TD><TD>    407.1 lpm</TD></TR>
<TR><TD>Shell scripts (1 concurrent)           </TD><TD>   756.0 lpm  </TD><TD>    567.9 lpm   </TD><TD>    572.2 lpm  </TD><TD>    628.6 lpm</TD></TR>
<TR><TD>Shell scripts (2 concurrent)           </TD><TD>   507.3 lpm  </TD><TD>    346.6 lpm   </TD><TD>    324.9 lpm  </TD><TD>    385.6 lpm</TD></TR>
<TR><TD>Shell scripts (4 concurrent)           </TD><TD>   271.0 lpm  </TD><TD>    183.0 lpm   </TD><TD>    163.9 lpm  </TD><TD>    208.3 lpm</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Shell scripts (8 concurrent)           </TD><TD>   137.7 lpm  </TD><TD>     93.0 lpm   </TD><TD>     82.0 lpm  </TD><TD>    107.0 lpm</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Dc: sqrt(2) to 99 decimal places       </TD><TD> 83900.0 lpm  </TD><TD>  52378.5 lpm   </TD><TD>  54949.6 lpm  </TD><TD>  25753.6 lpm</TD></TR>
<TR BGCOLOR="#EEEEEE"><TD>Recursion Test--Tower of Hanoi         </TD><TD>  7920.6 lps  </TD><TD>   8162.1 lps   </TD><TD>   8382.6 lps  </TD><TD>   7825.9 lps</TD></TR>
</TABLE>

<P>

<TABLE BORDER="0">
<TR><TD>INDEX VALUES</TD>                 <TD COLSPAN="3">FreeBSD-4.9</TD><TD COLSPAN="3">FreeBSD-5.1</TD>        <TD COLSPAN="3">FreeBSD-5.2</TD><TD COLSPAN="3">DragonFly</TD></TR>
<TR><TD>TEST                              </TD><TD>BASELINE    </TD><TD> RESULT      </TD><TD>INDEX  </TD><TD>BASELINE     </TD><TD>RESULT      </TD><TD>INDEX   </TD><TD>BASELINE     </TD><TD>RESULT      </TD><TD>INDEX    </TD><TD>BASELINE     </TD><TD>RESULT      </TD><TD>INDEX</TD></TR>
<TR><TD>Arithmetic Test (type = double)   </TD><TD BGCOLOR="#EEEEEE">2541.7  </TD><TD BGCOLOR="#EEEEEE">  88148.2     </TD><TD BGCOLOR="#EEEEEE">  34.7    </TD><TD>2541.7  </TD><TD> 104999.4      </TD><TD> 41.3    </TD> <TD BGCOLOR="#EEEEEE">2541.7</TD><TD BGCOLOR="#EEEEEE">105242.2</TD><TD BGCOLOR="#EEEEEE">41.4</TD><TD> 2541.7    </TD>  <TD>87891.6      </TD><TD> 34.6</TD></TR>
<TR><TD>Dhrystone 2 without register variables</TD><TD BGCOLOR="#EEEEEE">22366.3   </TD><TD BGCOLOR="#EEEEEE">660050.1      </TD><TD BGCOLOR="#EEEEEE"> 29.5  </TD><TD> 22366.3  </TD><TD> 650148.4      </TD><TD> 29.1    </TD><TD BGCOLOR="#EEEEEE">22366.3   </TD><TD BGCOLOR="#EEEEEE">661362.9      </TD><TD BGCOLOR="#EEEEEE"> 29.1    </TD><TD> 22366.3   </TD><TD>667712.8       </TD><TD>29.9</TD></TR>
<TR><TD>Execl Throughput Test             </TD><TD BGCOLOR="#EEEEEE">   16.5   </TD><TD BGCOLOR="#EEEEEE">  1772.9     </TD><TD BGCOLOR="#EEEEEE"> 107.4    </TD><TD>  16.5    </TD><TD> 1521.2      </TD><TD> 92.2    </TD> <TD BGCOLOR="#EEEEEE">16.5</TD><TD BGCOLOR="#EEEEEE">1371.7</TD><TD BGCOLOR="#EEEEEE">83.1</TD>  <TD> 16.5    </TD><TD> 1497.6       </TD><TD>90.8</TD></TR>
<TR><TD>File Copy  (30 seconds)           </TD><TD BGCOLOR="#EEEEEE">  179.0   </TD><TD BGCOLOR="#EEEEEE"> 15297.0     </TD><TD BGCOLOR="#EEEEEE">  85.5    </TD><TD> 179.0   </TD><TD> 11468.0      </TD><TD> 64.1    </TD> <TD BGCOLOR="#EEEEEE">179.0</TD><TD BGCOLOR="#EEEEEE">11811.0</TD><TD BGCOLOR="#EEEEEE">66.0</TD>  <TD> 179.0    </TD><TD>15308.0       </TD><TD>85.5</TD></TR>
<TR><TD>Pipe-based Context Switching Test </TD><TD BGCOLOR="#EEEEEE"> 1318.5    </TD><TD BGCOLOR="#EEEEEE">38436.5     </TD><TD BGCOLOR="#EEEEEE">  29.2   </TD><TD> 1318.5   </TD><TD> 23821.9      </TD><TD> 18.1    </TD> <TD BGCOLOR="#EEEEEE">1318.5</TD><TD BGCOLOR="#EEEEEE">23268.0</TD><TD BGCOLOR="#EEEEEE">17.6</TD>  <TD> 1318.5    </TD><TD>18203.4      </TD><TD> 13.8</TD></TR>
<TR><TD>Shell scripts (8 concurrent)      </TD><TD BGCOLOR="#EEEEEE">  4.0     </TD><TD BGCOLOR="#EEEEEE"> 137.7      </TD><TD BGCOLOR="#EEEEEE"> 34.4      </TD><TD> 4.0     </TD><TD>  93.0      </TD><TD> 23.2      </TD> <TD BGCOLOR="#EEEEEE"> 4.0</TD><TD BGCOLOR="#EEEEEE">82.0</TD><TD BGCOLOR="#EEEEEE">20.5</TD>  <TD> 4.0      </TD><TD>107.0       </TD><TD>26.8</TD></TR>
<TR><TD>                                  </TD><TD COLSPAN="3">                   =========             </TD><TD COLSPAN="3">          =========         </TD><TD COLSPAN="3">               =========             </TD><TD COLSPAN="3">            =========</TD></TR>
<TR><TD>     SUM of  6 items              </TD><TD COLSPAN="3">                       320.7             </TD><TD COLSPAN="3">              268.0         </TD><TD COLSPAN="3">                   258.2             </TD><TD COLSPAN="3">                281.3</TD></TR>
<TR><TD>     AVERAGE                      </TD><TD COLSPAN="3">                        53.4               </TD><TD COLSPAN="3">            44.7           </TD><TD COLSPAN="3">                   43.0              </TD><TD COLSPAN="3">                46.9</TD></TR>
</TABLE>

<P>

<TABLE BORDER="0">

<TR><TD COLSPAN="4">"Finally to test if there is a problem with the compiler I used the lorenz
benchmark (it simply does raw math computations, and does not use much memory)":</TD></TR>

<TR><TD COLSPAN="4">Lorenz on 5.1</TD></TR>
<TR><TD>4.9binary:</TD><TD>15.77 real</TD><TD>15.73 user</TD><TD>0.01 sys</TD></TR>
<TR><TD>5.1binary:</TD><TD>16.52 real</TD><TD>16.51 user</TD><TD>0.00 sys</TD></TR>
<TR><TD>5.2binary:</TD><TD>16.36 real</TD><TD>16.32 user</TD><TD>0.02 sys</TD></TR>
<TR><TD COLSPAN="4">Lorenz on 5.2</TD></TR>
<TR><TD>4.9binary:</TD><TD>19.35 real</TD><TD>18.12 user</TD><TD>1.14 sys</TD></TR>
<TR><TD>5.1binary:</TD><TD>27.65 real</TD><TD>26.05 user</TD><TD>1.48 sys</TD></TR>
<TR><TD>5.2binary:</TD><TD>29.61 real</TD><TD>27.60 user</TD><TD>1.87 sys</TD></TR>

<TR><TD COLSPAN="4">"The 5.1 results indicate that there is no problem with the compiler generated
code, but I don't know how to interpret the 5.2 results: I would expect also a bad behavior with
the 4.9 binary (all are static) Then I booted a uniprocessor kernel and reran the latest test:"</TD></TR>

<TR><TD COLSPAN="4">Lorenz on 5.2 UP</TD></TR>
<TR><TD>4.9binary:</TD><TD>15.80 real</TD><TD>15.71 user</TD><TD>0.02 sys</TD></TR>
<TR><TD>5.1binary:</TD><TD>22.57 real</TD><TD>22.45 user</TD><TD>0.03 sys</TD></TR>
<TR><TD>5.2binary:</TD><TD>24.16 real</TD><TD>24.05 user</TD><TD>0.03 sys</TD></TR>

</TABLE>

<P>

"I used the same kernel configuration file for the 4 systems. In particular I
removed 'cpu 486', maxusers was set to 0, and I don't have INVARIANTS or WITNESS options.
The kernels and the worlds were compiled with CFLAGS=-O -pipe.  /etc/malloc.conf is
always linked to aj.  I/O tests were done on the same filesystem
(IDE UDMA33 in all cases).  Bytebench binaries were compiled static.
I used the same binaries on FreeBSD 4.9-R and DragonFly; they were recompiled on
FreeBSD-5.[12] as the compiler is not the same."



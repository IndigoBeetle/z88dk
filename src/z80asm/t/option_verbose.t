#!/usr/bin/env perl

BEGIN { use lib 't'; require 'testlib.pl'; }

use Modern::Perl;

# verbose

my $asm = <<END;
	nop
	nop
	nop
END

# no -v
unlink_testfiles;
spew("${test}.asm", $asm);

capture_ok("z88dk-z80asm -b -s -l -g ${test}.asm", <<END);
END

check_bin_file("${test}.bin", bytes(0,0,0));

# -v
unlink_testfiles;
spew("${test}.asm", $asm);

capture_ok("z88dk-z80asm -b -s -l -g -v ${test}.asm", <<END);
Predefined constant: __CPU_Z80__ = 1
Predefined constant: __CPU_ZILOG__ = 1
Predefined constant: __FLOAT_GENMATH__ = 1
Reading library 'z88dk-z80asm.lib'
Assembling '${test}.asm' to '${test}.o'
Reading '${test}.asm' = '${test}.asm'
Writing object file '${test}.o'
Creating file '${test}.sym'

Code size: 3 bytes (\$0000 to \$0002)
Creating file '${test}.def'
Creating binary '${test}.bin'
END

check_bin_file("${test}.bin", bytes(0,0,0));
check_text_file("${test}.lis", <<END);
${test}.asm:
     1  0000  00                	nop
     2  0001  00                	nop
     3  0002  00                	nop
     4                          
END

check_text_file("${test}.def", <<END);
END

capture_ok("z88dk-z80asm -b -s -l -g -v ${test}.o", <<END);
Predefined constant: __CPU_Z80__ = 1
Predefined constant: __CPU_ZILOG__ = 1
Predefined constant: __FLOAT_GENMATH__ = 1
Reading library 'z88dk-z80asm.lib'
Append object file ${test}.o...
Code size: 3 bytes (\$0000 to \$0002)
Creating file '${test}.def'
Creating binary '${test}.bin'
END

check_bin_file("${test}.bin", bytes(0,0,0));
check_text_file("${test}.lis", <<END);
${test}.asm:
     1  0000  00                	nop
     2  0001  00                	nop
     3  0002  00                	nop
     4                          
END

check_text_file("${test}.def", <<END);
END

unlink_testfiles;
done_testing;

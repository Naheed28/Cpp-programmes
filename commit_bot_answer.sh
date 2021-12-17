#!/usr/bin/expect -f


set timeout 50

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"


expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

send "Yeap\n"

#!/usr/bin/expect -f


set timeout 50

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"


expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

send "Yeap\n"

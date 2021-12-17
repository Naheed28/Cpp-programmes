#!/usr/bin/expect -f


set timeout 50

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"


expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

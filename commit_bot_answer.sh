#!/usr/bin/expect -f


set timeout -1

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"


expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

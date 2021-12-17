#!/usr/bin/expect -f


set timeout 50

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"

set timeout 50
expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

#!/usr/bin/expect -f


set timeout 50

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"

set timeout 50
expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\n"
interact

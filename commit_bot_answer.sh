#!/usr/bin/expect -f

set timeout -1

spawn ./commit_bot.sh


expect "Username for 'https://github.com': "
send -- "NaheedRayan\r"

set timeout 10

expect "Password for 'https://NaheedRayan@github.com': "
send -- "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\r"



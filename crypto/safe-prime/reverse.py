import os

n = 292927367433510948901751902057717800692038691293351366163009654796102787183601223853665784238601655926920628800436003079044921928983307813012149143680956641439800408783429996002829316421340550469318295239640149707659994033143360850517185860496309968947622345912323183329662031340775767654881876683235701491291
c = 40791470236110804733312817275921324892019927976655404478966109115157033048751614414177683787333122984170869148886461684367352872341935843163852393126653174874958667177632653833127408726094823976937236033974500273341920433616691535827765625224845089258529412235827313525710616060854484132337663369013424587861

e = 65537

def solve_p():
  ok = 1
  ng = n
  while ng - ok > 1:
    mid = (ok + ng) // 2
    x = mid * (2 * mid + 1)
    if x <= n:
      ok = mid
    else:
      ng = mid
  return ok

p = solve_p()
q = 2 * p + 1

assert n == p * q

d = pow(e, -1, (p - 1) * (q - 1))
m = pow(c, d, n)

print(m.to_bytes((m.bit_length() + 7) // 8, 'big').decode())
# ctf4b{R3l4ted_pr1m3s_4re_vuLner4ble_n0_maTt3r_h0W_l4rGe_p_1s}
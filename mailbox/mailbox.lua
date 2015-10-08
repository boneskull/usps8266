local mailbox = {}

function send(data)
  local sock = net.createConnection(net.TCP, mailbox.config.mailbox.secure)
  sock:connect(mailbox.config.mailbox.port, mailbox.config.mailbox.host)
  sock:on('connection', function()
    sock:send(data)
  end)
  sock:on('sent', function()
    print('Transmission complete')
    sock:close()
  end)
end

function mailbox.sendOpened()
  if not mailbox.opened then
    mailbox.opened = true
    print('opened')
    send('opened')
  end
end

function mailbox.sendReset()
  print('reset')
  send('reset')
end

function mailbox.init(config)
  mailbox.opened = false
  mailbox.config = config

  gpio.mode(config.mailbox.resetPin, gpio.INT)
  gpio.mode(config.mailbox.switchPin, gpio.INT)
  gpio.trig(config.mailbox.resetPin, 'up', sendReset)
  gpio.trig(config.mailbox.switchPin, 'down', sendOpened)

  print('Mailbox ready')
end

return mailbox
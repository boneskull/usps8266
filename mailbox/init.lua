connect = require('connect')
mailbox = require('mailbox')

function init()

  if (not file.open('config.json', 'r')) then
    callback('No config.json present; cannot initialize')
    return
  end

  local config = cjson.decode(file.read())
  connect(config, function(err)
    if (err ~= nil) then
      return print(err)
    end

    mailbox.init(config)
  end)
end

init()
{
  "targets": [
    {
      "target_name": "fib",
      "sources": [ "fib.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}

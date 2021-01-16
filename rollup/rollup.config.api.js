import base from './rollup.config.base'

export default {
  ...base,
  input: 'lib/index.js',
  output: {
    ...base.output,
    file: 'bin/index.js'
  }
}

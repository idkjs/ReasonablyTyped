import base from './rollup.config.base'
import { preserveShebangs } from 'rollup-plugin-preserve-shebangs';

module.exports = {
  ...base,
  input: 'lib/cli.js',
  output: {
    ...base.output,
    file: 'bin/retyped.js',
    // banner: '#!/usr/bin/env node'
  },
  plugins: [
    preserveShebangs(),
  ],
};
// export default {
//   ...base,
//   input: 'lib/cli.js',
//   output: {
//     ...base.output,
//     file: 'cli.js',
//     banner: '#!/usr/bin/env node'
//   },
//     plugins: [...base.plugins,preserveShebangs()]
// }

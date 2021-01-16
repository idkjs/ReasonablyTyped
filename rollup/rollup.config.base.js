import commonjs from '@rollup/plugin-commonjs'
// import resolve from '@rollup/plugin-node-resolve'
import { nodeResolve } from '@rollup/plugin-node-resolve';
// import { preserveShebangs } from 'rollup-plugin-preserve-shebangs';

const dependencies = Object.keys(require('../package.json').dependencies)
const external = [...dependencies, 'reason', 'path', 'fs', 'process']

export default {
  output: {
    format: 'cjs',
    exports: 'named',
    interop: false,
  },
  external,
  plugins: [commonjs(), nodeResolve()]
}

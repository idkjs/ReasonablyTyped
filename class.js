declare module "classes" {
  declare type State = {
    id: number,
    storeName: string,
  }

  declare export class Store {
    constructor(initialState: State): Store;
    state: State;
    update(nextState: State): void;
  }
}

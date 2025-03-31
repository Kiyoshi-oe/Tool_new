import { ResourceItem, EffectData } from "../../types/fileTypes";
import { Input } from "../ui/input";
import { effectTypes } from "../../utils/resourceEditorUtils";
import { FormField } from "../ui/form-field";

interface StatsSectionProps {
  localItem: ResourceItem;
  editMode: boolean;
  handleEffectChange: (index: number, field: 'type' | 'value', value: string | number) => void;
}

const StatsSection = ({ localItem, editMode, handleEffectChange }: StatsSectionProps) => {
  return (
    <div className="mb-6">
      <h2 className="text-cyrus-blue text-lg font-semibold mb-2">Stats</h2>
      <div className="grid grid-cols-2 gap-4">
        {/* Support for up to 6 dwDestParam/nAdjParamVal pairs as per the spec_item.txt file format */}
        {Array.from({ length: 6 }).map((_, index) => (
          <div key={`effect-${index}`} className="form-field flex items-center space-x-2">
            <div className="flex-grow">
              <label className="form-label">Effect {index + 1}</label>
              <FormField
                id={`effect-type-${index}`}
                label=""
                type="select"
                value={localItem.effects[index]?.type || '-'}
                onChange={(value) => handleEffectChange(index, 'type', value)}
                disabled={!editMode}
                options={['-', ...effectTypes]}
                className="mt-0"
              />
            </div>
            <div className="w-24">
              <label className="form-label">&nbsp;</label>
              <Input
                type="text"
                className="form-input"
                disabled={!editMode || !localItem.effects[index]?.type || localItem.effects[index]?.type === '-'}
                value={localItem.effects[index]?.value || ''}
                onChange={(e) => handleEffectChange(index, 'value', e.target.value)}
              />
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default StatsSection;
